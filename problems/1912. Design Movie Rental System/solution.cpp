#include <bits/stdc++.h>
using namespace std;

struct Record
{
    int price;
    int shop;
    int movie;

    bool operator<(const Record &other) const
    {
        if (price != other.price)
            return price < other.price;
        if (shop != other.shop)
            return shop < other.shop;
        return movie < other.movie;
    }
};

class MovieRentingSystem
{
private:
    unordered_map<long long, int> priceMap;

    unordered_map<int, set<Record>> unrentedByMovie;

    set<Record> rented;

    long long encode(int shop, int movie)
    {
        return ((long long)shop << 32) | movie;
    }

public:
    MovieRentingSystem(int n, const vector<vector<int>> &entries)
    {
        for (auto &e : entries)
        {
            int shop = e[0], movie = e[1], price = e[2];
            long long key = encode(shop, movie);
            priceMap[key] = price;
            unrentedByMovie[movie].insert({price, shop, movie});
        }
    }

    vector<int> search(int movie)
    {
        vector<int> res;
        auto &movieSet = unrentedByMovie[movie];
        for (auto it = movieSet.begin(); it != movieSet.end() && res.size() < 5; ++it)
        {
            res.push_back(it->shop);
        }
        return res;
    }

    void rent(int shop, int movie)
    {
        long long key = encode(shop, movie);
        int price = priceMap[key];
        unrentedByMovie[movie].erase({price, shop, movie});
        rented.insert({price, shop, movie});
    }

    void drop(int shop, int movie)
    {
        long long key = encode(shop, movie);
        int price = priceMap[key];
        rented.erase({price, shop, movie});
        unrentedByMovie[movie].insert({price, shop, movie});
    }

    vector<vector<int>> report()
    {
        vector<vector<int>> res;
        for (auto it = rented.begin(); it != rented.end() && res.size() < 5; ++it)
        {
            res.push_back({it->shop, it->movie});
        }
        return res;
    }
};

/*
    Input:
    ["MovieRentingSystem","search","rent","rent","report","drop","search"]
    [[3,[[0,1,5],[0,2,6],[0,3,7],[1,1,4],[1,2,7],[2,1,5]]],[1],[0,1],[1,2],[],[1,2],[2]]

    Output:
    [null,[1,0,2],null,null,[[0,1],[1,2]],null,[0,1]]

*/

int main()
{
    MovieRentingSystem *obj = new MovieRentingSystem(3, {{0, 1, 5}, {0, 2, 6}, {0, 3, 7}, {1, 1, 4}, {1, 2, 7}, {2, 1, 5}});
    vector<int> param_1 = obj->search(1);
    obj->rent(0, 1);
    obj->rent(1, 2);
    vector<vector<int>> param_4 = obj->report();
    obj->drop(1, 2);
    vector<int> param_6 = obj->search(2);

    // Print results for verification
    cout << "Search(1): ";
    for (int shop : param_1)
    {
        cout << shop << " ";
    }
    cout << endl;

    cout << "Report: " << endl;
    for (const auto &entry : param_4)
    {
        cout << "[" << entry[0] << ", " << entry[1] << "]" << endl;
    }

    cout << "Search(2): ";
    for (int shop : param_6)
    {
        cout << shop << " ";
    }
    cout << endl;

    return 0;
}