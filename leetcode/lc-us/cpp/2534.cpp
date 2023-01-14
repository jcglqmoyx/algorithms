#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> timeTaken(vector<int> &arrival, vector<int> &state) {
        using PII = pair<int, int>;
        using PQII = priority_queue<PII, vector<PII>, greater<>>;
        PQII enter, exit;
        int n = (int) arrival.size();
        vector<int> res(n);

        for (int i = 0; i < n; i++) {
            if (!state[i]) enter.push({arrival[i], i});
            else exit.push({arrival[i], i});
        }

        int cur = -1, pre = -1, flag = 0;

        function<void(PQII &, int)> pop_queue = [&](PQII &q, int type) {
            auto t = q.top();
            q.pop();
            res[t.second] = cur;
            pre = cur;
            flag = type;
        };

        while (!exit.empty() || !enter.empty()) {
            if (!exit.empty() && !enter.empty()) {
                cur = max(cur + 1, min(exit.top().first, enter.top().first));
                if (exit.top().first <= cur && enter.top().first <= cur) {
                    if (cur - pre == 1) {
                        if (flag == 1) pop_queue(enter, 1);
                        else pop_queue(exit, 2);
                    } else {
                        if (exit.top().first <= enter.top().first) pop_queue(exit, 2);
                        else if (exit.top().first > enter.top().first) pop_queue(enter, 1);
                    }
                } else if (exit.top().first <= cur) {
                    pop_queue(exit, 2);
                } else if (enter.top().first <= cur) {
                    pop_queue(enter, 1);
                }
            } else if (!exit.empty()) {
                cur = max(cur + 1, exit.top().first);
                pop_queue(exit, 2);
            } else {
                cur = max(cur + 1, enter.top().first);
                pop_queue(enter, 1);
            }
        }
        return res;
    }
};