/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
    static bool cmp(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *res = new ListNode();
        ListNode *cur = res;
        priority_queue<ListNode *, vector<ListNode *>, decltype(&cmp)> pq(&cmp);
        for (int i = 0, n = lists.size(); i < n; i++)
            if (lists[i])
                pq.push(lists[i]);

        while (!pq.empty())
        {
            ListNode *node = pq.top();
            pq.pop();
            cur->next = node;
            cur = cur->next;
            if (node->next != nullptr)
                pq.push(node->next);
        }
        return res->next;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    // lists = [[1,4,5],[1,3,4],[2,6]]
    vector<ListNode *> lists;
    lists.push_back(new ListNode(1, new ListNode(4, new ListNode(5))));
    lists.push_back(new ListNode(1, new ListNode(3, new ListNode(4))));
    lists.push_back(new ListNode(2, new ListNode(6)));

    ListNode *node = sol.mergeKLists(lists);
    while (node != nullptr)
    {
        cout << node->val << " ";
        node = node->next;
    }
    return 0;
}