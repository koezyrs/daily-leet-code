#include <bits/stdc++.h>
using namespace std;

class Solution
{
    unordered_set<string> exactMatch;
    unordered_map<string, string> caseMatch;
    unordered_map<string, string> vowelMatch;

    bool isVowel(char c)
    {
        return c == 'U' || c == 'E' || c == 'O' || c == 'A' || c == 'I' ||
               c == 'u' || c == 'e' || c == 'o' || c == 'a' || c == 'i';
    }

    string toLower(string s)
    {
        for (char &c : s)
            c = tolower(c);
        return s;
    }

    string deVowel(string s)
    {
        for (char &c : s)
        {
            if (isVowel(c))
                c = '*';
            else
                c = (char)tolower(c);
        }
        return s;
    }

public:
    vector<string> spellchecker(vector<string> &wordlist,
                                vector<string> &queries)
    {
        int n = queries.size();
        vector<string> res;

        for (string s : wordlist)
        {
            string lower = toLower(s);
            string vower = deVowel(s);
            if (!caseMatch.count(lower))
                caseMatch[lower] = s;
            if (!vowelMatch.count(vower))
                vowelMatch[vower] = s;
            exactMatch.insert(s);
        }

        for (string s : queries)
        {
            if (exactMatch.count(s))
            {
                res.push_back(s);
            }
            else
            {
                string lower = toLower(s);
                string vowel = deVowel(s);
                if (caseMatch.count(lower))
                    res.push_back(caseMatch[lower]);
                else if (vowelMatch.count(vowel))
                    res.push_back(vowelMatch[vowel]);
                else
                    res.push_back("");
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<string> wordlist = {"zeo", "Zuo"};
    vector<string> queries = {"zuo"};
    vector<string> res = sol.spellchecker(wordlist, queries);
    for (string s : res)
        cout << "\"" << s << "\" ";
    cout << endl;
    return 0;
}