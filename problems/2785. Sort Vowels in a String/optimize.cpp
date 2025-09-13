#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string sortVowels(string s)
    {
        int n = s.size();
        int cnt[118] = {0};
        bool isVowel[256] = {false};
        char vowels[10] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};

        for (int i = 0; i < 10; i++)
        {
            isVowel[vowels[i]] = true;
        }

        for (int i = 0; i < n; i++)
        {
            if (isVowel[s[i]])
            {
                cnt[s[i]]++;
            }
        }

        int idx = 0;
        for (int i = 0; i < n; i++)
        {
            if (isVowel[s[i]])
            {
                while (cnt[vowels[idx]] == 0)
                    idx++;
                cnt[vowels[idx]]--;
                s[i] = vowels[idx];
            }
        }
        return s;
    }
};

int main()
{
    Solution sol;
    cout << sol.sortVowels("lYmpH") << endl; // Output: lEOtcede
    return 0;
}

/*

l E e t c O d e
0 1 1 0 0 1 0 1

*/