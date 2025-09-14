#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateSchedule(int n)
    {
        vector<vector<bool>> isDone(n, vector<bool>(n, false));
        if (n <= 3)
            return {};

        vector<vector<int>> res;
        int matchNum[n];
        for (int i = 0; i < n; i++)
            matchNum[i] = 2 * n + 1;
        int maxMatch = n * n - n;
        int lastTeam1 = -1;
        int lastTeam2 = -1;

        while (res.size() < maxMatch)
        {
            int team1 = 0, team2 = 0;
            int minMatch = INT_MAX;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i == j || isDone[i][j] || i == lastTeam1 || i == lastTeam2 || j == lastTeam1 || j == lastTeam2)
                        continue;

                    if (matchNum[i] + matchNum[j] < minMatch)
                    {
                        minMatch = matchNum[i] + matchNum[j];
                        team1 = i;
                        team2 = j;
                    }
                }
            }

            res.push_back({team1, team2});
            matchNum[team1]--;
            matchNum[team2]--;
            isDone[team1][team2] = true;
            lastTeam1 = team1;
            lastTeam2 = team2;
        }
        return res;
    }
};

int main()
{
    // Input: n = 5
    // Output: [[0,1],[2,3],[0,4],[1,2],[3,4],[0,2],[1,3],[2,4],[0,3],[1,4],[2,0],[3,1],[4,0],[2,1],[4,3],[1,0],[3,2],[4,1],[3,0],[4,2]]

    Solution sol;
    vector<vector<int>> schedule = sol.generateSchedule(5);
    for (const auto &match : schedule)
    {
        cout << "[" << match[0] << "," << match[1] << "],";
    }
    cout << endl;
    return 0;
}