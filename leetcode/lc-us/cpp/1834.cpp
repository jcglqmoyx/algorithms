#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getOrder(vector<vector<int>> &tasks) {
        int n = (int) tasks.size();
        for (int i = 0; i < n; i++) {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end(), [&](const vector<int> &a, const vector<int> &b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] < b[1];
        });
        auto cmp = [&](int i, int j) {
            if (tasks[i][1] != tasks[j][1]) return tasks[i][1] > tasks[j][1];
            return tasks[i][2] > tasks[j][2];
        };
        priority_queue<int, vector<int>, decltype(cmp)> heap(cmp);
        int cur = 0;
        vector<int> res;
        for (int i = 0; i < n;) {
            while (i < n && tasks[i][0] <= cur) {
                heap.push(i++);
            }
            if (!heap.empty()) {
                int t = heap.top();
                heap.pop();
                cur += tasks[t][1];
                res.push_back(tasks[t][2]);
            } else {
                res.push_back(tasks[i][2]);
                cur = tasks[i][0] + tasks[i][1];
                i++;
            }
        }
        while (!heap.empty()) {
            res.push_back(tasks[heap.top()][2]);
            heap.pop();
        }
        return res;
    }
};