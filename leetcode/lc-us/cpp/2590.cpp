#include <bits/stdc++.h>

using namespace std;

class TodoList {
    struct Task {
        int id;
        int user_id;
        string task_description;
        int due_date;
        vector<string> tags;
    };
    int id = 1;
    unordered_map<int, vector<Task>> hash;
public:
    TodoList() {
    }

    int addTask(int userId, string taskDescription, int dueDate, vector<string> tags) {
        hash[userId].push_back({id, userId, taskDescription, dueDate, tags});
        sort(hash[userId].begin(), hash[userId].end(), [](const Task &a, const Task &b) {
            return a.due_date < b.due_date;
        });
        return id++;
    }

    vector<string> getAllTasks(int userId) {
        vector<string> res;
        for (auto &t: hash[userId]) {
            res.push_back(t.task_description);
        }
        return res;
    }

    vector<string> getTasksForTag(int userId, string tag) {
        vector<string> res;
        for (auto &t: hash[userId]) {
            if (find(t.tags.begin(), t.tags.end(), tag) != t.tags.end()) {
                res.push_back(t.task_description);
            }
        }
        return res;
    }

    void completeTask(int userId, int taskId) {
        auto &tasks = hash[userId];
        for (int i = 0; i < tasks.size(); i++) {
            if (tasks[i].id == taskId) {
                tasks.erase(tasks.begin() + i);
                break;
            }
        }
    }
};