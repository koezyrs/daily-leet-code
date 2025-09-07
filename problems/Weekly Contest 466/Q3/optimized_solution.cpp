#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
    long long bowlSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        long long res = 0;
        int leftGreater[n];
        int rightGreater[n];

        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            leftGreater[i] = -1;
            rightGreater[i] = -1;
        }

        // Find left greater
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();

            if (!st.empty())
                leftGreater[i] = st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Find right greater
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();

            if (!st.empty())
                rightGreater[i] = st.top();

            st.push(i);
        }

        for (int i = 0; i < n; i++)
        {
            if (leftGreater[i] != -1 && rightGreater[i] != -1)
                res++;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 5, 3, 1, 4};
    cout << sol.bowlSubarrays(nums) << endl;
    return 0;
}