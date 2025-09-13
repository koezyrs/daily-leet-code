#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumTeachings(int n, vector<vector<int>> &languages, vector<vector<int>> &friendships)
    {
        int res = INT_MAX;
        int m = languages.size();
        int size = friendships.size();
        int numToTeach = 0;
        vector<bool> isTeach(m, false);

        // Thu tung so 1
        for (int i = 1; i <= n; i++)
        {
            numToTeach = 0;
            isTeach = vector<bool>(m, false);
            for (int j = 0; j < size; j++)
            {
                int u = friendships[j][0];
                int v = friendships[j][1];
                bool inCommon = false;
                for (int k = 0; k < languages[u - 1].size(); k++)
                {
                    if (find(languages[v - 1].begin(), languages[v - 1].end(), languages[u - 1][k]) != languages[v - 1].end())
                    {
                        inCommon = true;
                        break;
                    }
                }

                if (inCommon)
                    continue;

                if (find(languages[u - 1].begin(), languages[u - 1].end(), i) == languages[u - 1].end() && !isTeach[u - 1])
                {
                    isTeach[u - 1] = true;
                    numToTeach++;
                }

                if (find(languages[v - 1].begin(), languages[v - 1].end(), i) == languages[v - 1].end() && !isTeach[v - 1])
                {
                    isTeach[v - 1] = true;
                    numToTeach++;
                }
            }
            res = min(res, numToTeach);
        }

        return res;
    }
};

int main()
{
    Solution sol;
    int n = 3;
    vector<vector<int>> languages = {{2}, {1, 3}, {1, 2}, {3}};
    vector<vector<int>> friendships = {{1, 4}, {1, 2}, {3, 4}, {2, 3}};
    cout << sol.minimumTeachings(n, languages, friendships) << endl; // Output: 1
    return 0;
}

/*

    int n = 3;
    vector<vector<int>> languages = {{2}, {1, 3}, {1, 2}, {3}};
    vector<vector<int>> friendships = {{1, 4}, {1, 2}, {3, 4}, {2, 3}};
*/

/*
    int n = 2;
    vector<vector<int>> languages = {{1}, {2}, {1, 2}};
    vector<vector<int>> friendships = {{1, 2}, {1, 3}, {2, 3}};
*/