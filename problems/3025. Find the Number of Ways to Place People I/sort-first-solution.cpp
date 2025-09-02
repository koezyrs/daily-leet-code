#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        int xA = a[0], yA = a[1];
        int xB = b[0], yB = b[1];
        return (xA == xB) ? yA > yB : xA < xB;
    }

    int numberOfPairs(vector<vector<int>> &points)
    {
        int res = 0;
        int n = points.size();
        sort(points.begin(), points.end(), cmp);

        for (int i = 0; i < n - 1; i++)
        {
            int yMax = INT_MIN;
            for (int j = i + 1; j < n; j++)
            {
                int yA = points[i][1];
                int yB = points[j][1];
                if (yB <= yA && yB > yMax)
                {
                    res++;
                    yMax = yB;
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> points = {{3, 1}, {1, 3}, {1, 1}};
    cout << sol.numberOfPairs(points) << endl;
    return 0;
}