#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double largestTriangleArea(vector<vector<int>> &points)
    {
        int n = points.size();
        double maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    double area = abs((points[j][0] - points[i][0]) * (points[k][1] - points[i][1]) -
                                      (points[k][0] - points[i][0]) * (points[j][1] - points[i][1])) /
                                  2.0;
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> points = {{0, 0}, {0, 1}, {1, 0}, {0, 2}, {2, 0}};
    cout << sol.largestTriangleArea(points) << endl;
    return 0;
}