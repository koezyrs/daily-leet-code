#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfPairs(vector<vector<int>> &points)
    {
        int res = 0;
        int n = points.size();
        for (int i = 0; i < n; i++)
        {
            int xA = points[i][0];
            int yA = points[i][1];
            for (int j = 0; j < n; j++)
            {
                if (j == i)
                    continue;

                int xB = points[j][0];
                int yB = points[j][1];

                if (xA > xB || yA < yB)
                    continue;

                bool ok = true;
                for (int k = 0; k < n; k++)
                {
                    if (k == i || k == j)
                        continue;

                    int xC = points[k][0];
                    int yC = points[k][1];

                    if (xC >= xA && xC <= xB && yC <= yA && yC >= yB)
                    {
                        ok = false;
                        break;
                    }
                }

                res += (ok) ? 1 : 0;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> points = {{6, 2}, {4, 4}, {2, 6}};
    cout << sol.numberOfPairs(points) << endl;
    return 0;
}