#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string sortVowels(string s)
    {
        int n = s.size();
        vector<int> vowelIndexes;
        vector<int> vowels;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
                s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                vowelIndexes.push_back(i);
                vowels.push_back((int)s[i]);
            }
        }

        sort(vowels.begin(), vowels.end());

        for (int i = 0, size = vowels.size(); i < size; i++)
        {
            s[vowelIndexes[i]] = vowels[i];
        }
        return s;
    }
};

int main()
{
    Solution sol;
    cout << sol.sortVowels("lEetcOde") << endl; // Output: lEOtcede
    return 0;
}