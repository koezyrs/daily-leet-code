#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findClosest(int x, int y, int z)
    {
        return (abs(z - x) == abs(z - y)) ? 0 : (abs(z - x) < abs(z - y) ? 1 : 2);
    }
};

int main()
{
    Solution sol;
    int result = sol.findClosest(1, 2, 3);
    cout << result << endl; // Output: 2
    return 0;
}