#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        string num = "";
        vector<int> revision1, revision2;
        for (int i = 0, n = version1.size(); i < n; i++)
        {
            if (version1[i] == '.')
            {
                revision1.push_back(stoi(num));
                num = "";
                continue;
            }

            num += version1[i];
        }
        revision1.push_back(stoi(num));

        num = "";
        for (int i = 0, n = version2.size(); i < n; i++)
        {
            if (version2[i] == '.')
            {
                revision2.push_back(stoi(num));
                num = "";
                continue;
            }

            num += version2[i];
        }
        revision2.push_back(stoi(num));

        if (revision1.size() < revision2.size())
            revision1.resize(revision2.size(), 0);
        else if (revision1.size() > revision2.size())
            revision2.resize(revision1.size(), 0);

        int i = 0, n = revision1.size(), m = revision2.size();
        while (i < n && i < m)
        {
            if (revision1[i] < revision2[i])
                return -1;
            if (revision1[i] > revision2[i])
                return 1;
            i++;
        }
        return 0;
    }
};

int main()
{
    Solution sol;
    string version1 = "1.0", version2 = "1.0.0.0";
    cout << sol.compareVersion(version1, version2) << endl;
    return 0;
}