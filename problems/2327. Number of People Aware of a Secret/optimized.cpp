#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int modulo = 1e9 + 7;

public:
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        int dp[1001] = {0};
        int sum = 0;
        int res = 1;
        dp[1] = 1;
        for (int day = 2; day <= n; day++)
        {
            if (day > delay)
                sum = ((long long)sum + dp[day - delay]) % modulo;
            if (day > forget)
            {
                sum = ((long long)sum - dp[day - forget] + modulo) % modulo;
                res = ((long long)res - dp[day - forget] + modulo) % modulo;
            }

            dp[day] = sum;
            res = ((long long)res + dp[day]) % modulo;
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