#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int modulo = 1e9 + 7;

public:
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        vector<vector<int>> dp = vector<vector<int>>(n + 1, vector<int>(forget + 1, 0));
        int res = 0;
        dp[1][1] = 1;

        for (int day = 2; day <= n; day++)
        {
            long long sum = 0;
            for (int knownFor = forget; knownFor >= 1; knownFor--)
            {
                if (knownFor == 1)
                {
                    dp[day][knownFor] = sum;
                }
                else
                {
                    int num = dp[day - 1][knownFor - 1];
                    dp[day][knownFor] = num;
                    if (day > delay && knownFor > delay)
                        sum = (sum + num) % modulo;
                }
                if (day == n)
                {
                    res = (res + dp[n][knownFor]) % modulo;
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    // 4, 1, 3
    // 6, 2, 4
    cout << sol.peopleAwareOfSecret(6, 2, 4) << endl;
    return 0;
}