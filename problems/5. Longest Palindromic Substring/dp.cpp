#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool dp[1000][1000];

public:
    string longestPalindrome(string s)
    {
        string res = "";
        int n = s.size();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp[i][j] = false;

        for (int i = 0; i < n; i++)
        {
            if (res.size() < 1)
                res = s.substr(i, 1);
            dp[i][i] = true;
        }

        for (int i = 0; i < n - 1; i++)
        {
            dp[i][i + 1] = (s[i] == s[i + 1]);
            if (dp[i][i + 1] && res.size() < 2)
                res = s.substr(i, 2);
        }

        int len = 3;
        while (len <= n)
        {
            for (int i = 0; i < n - len + 1; i++)
            {
                int j = i + len - 1;
                dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                if (dp[i][j] && res.size() < len)
                {
                    res = s.substr(i, len);
                }
            }
            len++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    string s = "cbbd";
    cout << sol.longestPalindrome(s) << endl;
    return 0;
}