#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> replaceNonCoprimes(vector<int> &nums)
    {
        stack<int> st;
        for (int num : nums)
        {
            while (!st.empty())
            {
                int g = gcd(st.top(), num);
                if (g == 1)
                    break;
                num = num / g * st.top();
                st.pop();
            }
            st.push(num);
        }
        
        vector<int> result;
        while (!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {6, 4, 3, 2, 7, 6, 2};
    vector<int> result = sol.replaceNonCoprimes(nums);
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}