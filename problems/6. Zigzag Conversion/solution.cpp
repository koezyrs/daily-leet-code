#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;

        vector<vector<char>> zigZag = vector<vector<char>>(numRows, vector<char>());
        int direction = 1;
        int n = s.size();
        int k = 0;

        for (int i = 0; i < n; i++)
        {
            zigZag[k].push_back(s[i]);
            if (k + direction == numRows || k + direction == -1)
                direction *= -1;
            k += direction;
        }

        string res;
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0, cap = zigZag[i].size(); j < cap; j++)
            {
                char c = zigZag[i][j];
                res += c;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    string s = "PAYPALISHIRING";
    int numRows = 3;
    cout << sol.convert(s, numRows) << endl; // Output: "PAHNAPLSIIGYIR"
    return 0;
}