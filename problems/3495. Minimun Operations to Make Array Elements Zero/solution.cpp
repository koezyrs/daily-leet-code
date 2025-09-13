#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minOperations(vector<vector<int>> &queries)
    {
        long long res = 0;
        int numOfQueries = queries.size();
        while (numOfQueries)
        {
            solve(queries[numOfQueries - 1], res);
            numOfQueries--;
        }
        return res;
    }

    void solve(const vector<int> &nums, long long &res)
    {
        int left = nums[0];
        int right = nums[1];
        long long sum = 0;

        int start = left, op = floor(log(left) / log(4)) + 1;
        int end = pow(4, op) - 1;

        while (end <= right)
        {
            sum += 1LL * op * (end - start + 1);
            start = end + 1;
            op++;
            end = start * 4 - 1;
        }

        if (start <= right)
            sum += 1LL * op * (right - start + 1);

        res += (sum % 2 == 0) ? sum / 2 : sum / 2 + 1;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> queries = {{8, 15}, {2, 16}, {9, 23}, {15, 21}, {13, 17}};
    cout << sol.minOperations(queries) << endl;

    return 0;
}