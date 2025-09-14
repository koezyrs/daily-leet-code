#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int smallestAbsent(vector<int> &nums)
    {
        double sum = 0;
        unordered_map<int, bool> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            mp[nums[i]] = true;
        }
        sum /= n;
        int start = (ceil(sum) > floor(sum)) ? ceil(sum) : ceil(sum) + 1;
        if (start <= 0)
            start = 1;
        int res = 0;
        for (int i = start; i <= 101; i++)
        {
            if (mp[i])
                continue;
            res = i;
            break;
        }

        return res;
    }
};

int main()
{
    return 0;
}