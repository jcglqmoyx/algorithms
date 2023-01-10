#include <bits/stdc++.h>

using namespace std;

/*
 * endlesscheng https://leetcode.cn/problems/time-to-cross-a-bridge/solution/by-endlesscheng-nzqo/
 */
class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>> &time) {
        stable_sort(time.begin(), time.end(), [](auto &a, auto &b) {
            return a[0] + a[2] < b[0] + b[2];
        });
        priority_queue<pair<int, int>> waitL, waitR;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> workL, workR;
        for (int i = k - 1; i >= 0; --i) waitL.emplace(i, 0);
        int cur = 0;
        while (n) {
            while (!workL.empty() && workL.top().first <= cur) {
                auto[t, i] = workL.top();
                workL.pop();
                waitL.emplace(i, t);
            }
            while (!workR.empty() && workR.top().first <= cur) {
                auto[t, i] = workR.top();
                workR.pop();
                waitR.emplace(i, t);
            }
            if (!waitR.empty()) {
                auto[i, t] = waitR.top();
                waitR.pop();
                cur += time[i][2];
                workL.emplace(cur + time[i][3], i);
            } else if (!waitL.empty()) {
                auto[i, t] = waitL.top();
                waitL.pop();
                cur += time[i][0];
                workR.emplace(cur + time[i][1], i);
                --n;
            } else if (workL.empty()) cur = workR.top().first;
            else if (workR.empty()) cur = workL.top().first;
            else cur = min(workL.top().first, workR.top().first);
        }
        while (!workR.empty()) {
            auto[t, i] = workR.top();
            workR.pop();
            cur = max(t, cur) + time[i][2];
        }
        return cur;
    }
};