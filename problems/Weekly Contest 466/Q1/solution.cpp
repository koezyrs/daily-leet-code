#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] != nums[i + 1])
                return 1;
        }
        return 0;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2};
    cout << sol.minOperations(nums) << endl;
    return 0;
}