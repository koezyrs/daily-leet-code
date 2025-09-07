#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sumZero(int n)
    {
        vector<int> res;
        for (int i = 1; i <= n / 2; i++)
        {
            res.push_back(i);
            res.push_back(-i);
        }
        if (n % 2 == 1)
            res.push_back(0);
        return res;
    }
};

int main()
{
    Solution sol;
    int n = 5;
    vector<int> res = sol.sumZero(n);
    for (int num : res)
        cout << num << " ";
    cout << endl;
    return 0;
}