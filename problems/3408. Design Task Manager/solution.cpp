#include <bits/stdc++.h>
using namespace std;

struct Task
{
    int userId;
    int taskId;
    int priority;

    Task()
    {
        userId = -1;
        taskId = -1;
        priority = 0;
    }

    Task(int userId, int taskId, int priority)
    {
        this->userId = userId;
        this->taskId = taskId;
        this->priority = priority;
    }
};

class TaskManager
{
    unordered_map<int, Task> tasks;
    priority_queue<pair<int, int>> pq;

    bool normalizeTop()
    {
        while (!pq.empty())
        {
            auto [pr, id] = pq.top();
            auto it = tasks.find(id);
            if (it == tasks.end() || it->second.priority != pr)
            {
                pq.pop();
                continue;
            }
            return true;
        }
        return false;
    }

public:
    TaskManager(vector<vector<int>> &init)
    {
        for (const auto &t : init)
        {
            int userId = t[0], taskId = t[1], priority = t[2];
            tasks[taskId] = Task(userId, taskId, priority);
            pq.emplace(priority, taskId);
        }
    }

    void add(int userId, int taskId, int priority)
    {
        tasks[taskId] = Task(userId, taskId, priority);
        pq.emplace(priority, taskId);
    }

    void edit(int taskId, int newPriority)
    {
        auto it = tasks.find(taskId);
        if (it == tasks.end())
            return;
        it->second.priority = newPriority;
        pq.emplace(newPriority, taskId);
    }

    void rmv(int taskId)
    {
        tasks.erase(taskId);
    }

    int execTop()
    {
        if (!normalizeTop())
            return -1;
        auto [pr, id] = pq.top();
        int userId = tasks[id].userId;
        tasks.erase(id);
        pq.pop();
        return userId;
    }
};

/**
    Input: ["TaskManager","add","edit","execTop","rmv","add","execTop"]

    [[[[1,101,10],[2,102,20],[3,103,15]]],[4,104,5],[102,8],[],[101],[5,105,15],[]]


    Expected: [null,null,null,3,null,null,5]

 */

int main()
{
    vector<vector<int>> tasks = {{1, 101, 10}, {2, 102, 20}, {3, 103, 15}};
    TaskManager *obj = new TaskManager(tasks);
    obj->add(4, 104, 5);
    obj->edit(102, 8);
    cout << obj->execTop() << endl;
    obj->rmv(101);
    obj->add(5, 105, 15);
    cout << obj->execTop() << endl;

    return 0;
}