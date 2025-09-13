#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFreqSum(string s)
    {
        int letter[26] = {0};
        const int vowelMask =
            (1 << 0) | (1 << 4) | (1 << 8) | (1 << 14) | (1 << 20);
        int vowelMax = 0, consonantMax = 0;
        for (int i = 0, n = s.size(); i < n; i++)
        {
            int idx = s[i] - 'a';
            letter[idx]++;
            if (vowelMask & (1 << idx))
                vowelMax = max(vowelMax, letter[idx]);
            else
                consonantMax = max(consonantMax, letter[idx]);
        }

        return vowelMax + consonantMax;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    string s = "successes";
    cout << sol.maxFreqSum(s) << endl;
    return 0;
}