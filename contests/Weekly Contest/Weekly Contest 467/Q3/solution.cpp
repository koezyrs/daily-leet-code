#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> subsequenceSumAfterCapping(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<bool> res;
        for (int x = 1; x <= n; x++)
        {
            vector<int> capped = transformArray(nums, n, x);
            res.push_back(solve(capped, n, k));
        }
        return res;
    }

    vector<int> transformArray(vector<int> nums, int n, int x)
    {
        for (int i = 0; i < n; i++)
        {
            nums[i] = min(nums[i], x);
        }
        return nums;
    }

    bool solve(vector<int> capped, int n, int k)
    {
        vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));
        for (int i = 0; i <= n; i++)
            dp[i][0] = true;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= capped[i - 1])
                {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - capped[i - 1]];
                }
            }
        }

        return dp[n][k];
    }
};

int main()
{
    // Input: nums = [14,8,9,10,13,5,15,15,1,14,3,15,2,2,15], k = 35
    // Output: [true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true]
    Solution sol;
    vector<int> nums = {14, 8, 9, 10, 13, 5, 15, 15, 1, 14, 3, 15, 2, 2, 15};
    int k = 35;
    vector<bool> res = sol.subsequenceSumAfterCapping(nums, k);
    for (bool b : res)
        cout << (b ? "true" : "false") << " ";
    cout << endl;
    return 0;
}