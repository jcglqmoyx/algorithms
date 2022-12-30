#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> assignTasks(vector<int> &servers, vector<int> &tasks) {
        using PII = pair<int, int>;
        auto cmp1 = [&](int a, int b) {
            if (servers[a] == servers[b]) return a > b;
            return servers[a] > servers[b];
        };
        auto cmp2 = [&](const PII &a, const PII &b) {
            if (a.first != b.first) return a.first > b.first;
            if (servers[a.second] != servers[b.second]) return servers[a.second] > servers[b.second];
            return a.second > b.second;
        };
        priority_queue<int, vector<int>, decltype(cmp1)> idle(cmp1);
        priority_queue<PII, vector<PII>, decltype(cmp2)> busy(cmp2);
        for (int i = 0; i < servers.size(); i++) idle.push(i);
        int n = (int) tasks.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            while (!busy.empty() && busy.top().first <= i) {
                idle.push(busy.top().second);
                busy.pop();
            }
            if (idle.empty()) {
                auto t = busy.top();
                busy.pop();
                res[i] = t.second;
                busy.push({t.first + tasks[i], t.second});
            } else {
                auto t = idle.top();
                idle.pop();
                res[i] = t;
                busy.push({i + tasks[i], t});
            }
        }
        return res;
    }
};