#include <bits/stdc++.h>
using namespace std;

/*
    This solution uses dynamic programming to find the number of "bowl" subarrays.

    This version of code get "Memory Limit Exceeded" error on LeetCode.
    The reason is that it uses a 2D vector `dp` of size n x n, where n is the size of the input array `nums`.
    This can lead to high memory usage, especially for large input sizes. xD

    Check out optimized solution in dp_optimized_solution.cpp for better approach.
*/
class Solution
{

public:
    long long bowlSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        int res = 0;
        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = 0; i < n - 1; i++)
        {
            dp[i][i + 1] = max(nums[i], nums[i + 1]);
        }

        for (int i = 0; i < n - 2; i++)
        {
            if (min(nums[i], nums[i + 2]) > nums[i + 1])
                res++;
            dp[i][i + 2] = max(max(nums[i], nums[i + 2]), nums[i + 1]);
        }

        int len = 4;
        while (len <= n)
        {
            int start = 0;
            int end = 0;
            while (start <= n - len)
            {
                end = start + len - 1;
                if (min(nums[start], nums[end]) > dp[start + 1][end - 1])
                    res++;
                dp[start][end] = max(max(nums[start], nums[end]), dp[start + 1][end - 1]);
                start++;
            }
            len++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 5, 3, 1, 4};
    cout << sol.bowlSubarrays(nums) << endl;
    return 0;
}