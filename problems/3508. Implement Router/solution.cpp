#include <bits/stdc++.h>
using namespace std;

struct Packet
{
    int source, destination, timestamp;
};

struct PacketKey
{
    int source, destination, timestamp;
    bool operator==(const PacketKey &o) const
    {
        return source == o.source && destination == o.destination && timestamp == o.timestamp;
    }
};

struct PacketKeyHash
{
    size_t operator()(const PacketKey &k) const
    {
        return ((size_t)k.source * 73856093) ^
               ((size_t)k.destination * 19349663) ^
               ((size_t)k.timestamp * 83492791);
    }
};

class Router
{
    int memoryLimit;
    unordered_map<PacketKey, Packet, PacketKeyHash> packets;
    unordered_map<int, deque<int>> destToTimestamps;
    queue<PacketKey> packetsOrder;

public:
    Router(int memoryLimit) : memoryLimit(memoryLimit)
    {
        packets.reserve(memoryLimit);
        destToTimestamps.reserve(memoryLimit);
    }

    bool addPacket(int source, int destination, int timestamp)
    {
        PacketKey key{source, destination, timestamp};
        if (packets.count(key))
            return false;

        if ((int)packets.size() == memoryLimit)
        {
            auto oldestKey = packetsOrder.front();
            packetsOrder.pop();
            auto oldest = packets[oldestKey];
            packets.erase(oldestKey);

            destToTimestamps[oldest.destination].pop_front();
        }

        packets[key] = {source, destination, timestamp};
        packetsOrder.push(key);
        destToTimestamps[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket()
    {
        if (packetsOrder.empty())
            return {};
        auto key = packetsOrder.front();
        packetsOrder.pop();
        auto pkt = packets[key];
        packets.erase(key);

        destToTimestamps[pkt.destination].pop_front();

        return {pkt.source, pkt.destination, pkt.timestamp};
    }

    int getCount(int destination, int startTime, int endTime)
    {
        auto &timestamps = destToTimestamps[destination];
        auto itStart = lower_bound(timestamps.begin(), timestamps.end(), startTime);
        auto itEnd = upper_bound(timestamps.begin(), timestamps.end(), endTime);
        return distance(itStart, itEnd);
    }
};

/**
    Input:
    ["Router","addPacket","addPacket","addPacket","addPacket","addPacket","forwardPacket","addPacket","getCount"]
    [[3],[1,4,90],[2,5,90],[1,4,90],[3,5,95],[4,5,105],[],[5,2,110],[5,100,110]]

    Expected Output:
    [null,true,true,false,true,true,[2,5,90],true,1]
 */

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Router *obj = new Router(3);
    cout << obj->addPacket(1, 4, 90) << "\n";  // true
    cout << obj->addPacket(2, 5, 90) << "\n";  // true
    cout << obj->addPacket(1, 4, 90) << "\n";  // false
    cout << obj->addPacket(3, 5, 95) << "\n";  // true
    cout << obj->addPacket(4, 5, 105) << "\n"; // true
    auto p = obj->forwardPacket();
    cout << "[" << p[0] << "," << p[1] << "," << p[2] << "]\n"; // [2,5,90]
    cout << obj->addPacket(5, 2, 110) << "\n";                  // true
    cout << obj->getCount(5, 100, 110) << "\n";                 // 1

    delete obj;
    return 0;
}