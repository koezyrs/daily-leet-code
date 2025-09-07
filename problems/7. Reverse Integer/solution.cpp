#include <bits/stdc++.h>
#include <string>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        string num = to_string(x);
        long long res = 0;
        if (x < 0)
        {
            ::reverse(num.begin() + 1, num.end());
            res = -stoll(num.substr(1));
        }
        else
        {
            ::reverse(num.begin(), num.end());
            res = stoll(num);
        }

        if (res < INT_MIN || res > INT_MAX)
            res = 0;
        return res;
    }
};

int main()
{
    Solution sol;
    int x = 123;
    cout << sol.reverse(x) << endl;
    return 0;
}