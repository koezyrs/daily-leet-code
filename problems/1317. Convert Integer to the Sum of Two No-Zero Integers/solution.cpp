#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getNoZeroIntegers(int n)
    {
        vector<int> res;
        string valA, valI;
        int dummy;
        for (int i = 1; i <= n / 2; i++)
        {
            valI = to_string(i);
            if (valI.find('0') != std::string::npos)
                continue;

            dummy = n - i;
            valA = to_string(dummy);
            if (valA.find('0') != std::string::npos)
                continue;

            res.push_back(dummy);
            res.push_back(i);
            break;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    int n = 1010;
    vector<int> res = sol.getNoZeroIntegers(n);
    for (auto x : res)
        cout << x << " ";
    cout << endl;
    return 0;
}