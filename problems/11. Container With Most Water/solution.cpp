#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int res = 0;
        int i = 0, j = height.size() - 1;
        while (true)
        {
            int w = j - i;
            int h = (height[i] < height[j]) ? height[i] : height[j];
            res = max(res, w * h);

            if (j - i == 1)
                break;

            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << sol.maxArea(height) << endl;
    return 0;
}