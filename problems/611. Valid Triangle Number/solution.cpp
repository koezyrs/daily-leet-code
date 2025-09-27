#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        int n = nums.size();

        if (n < 3)
            return 0;

        int res = 0;
        sort(nums.begin(), nums.end());
        int start = 0;
        while (nums[start] == 0)
            start++;

        int i = start;
        for (int k = n - 1; k >= 2; k--)
        {
            int i = start;
            for (int j = k - 1; j > i; j--)
            {
                while (j > i && nums[i] + nums[j] <= nums[k])
                    i++;
                if (i >= j)
                    continue;
                res += (j - i);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {0, 1, 1, 1};
    cout << sol.triangleNumber(nums) << endl;
    return 0;
}