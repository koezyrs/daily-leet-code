#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(string s)
    {
        int n = s.size();
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a')
                continue;
            res = max(res, 123 - (int)(s[i]));
        }
        return res;
    }
};

int main()
{
    Solution sol;
    string s = "xyyyz";
    cout << sol.minOperations(s) << endl;
    return 0;
}