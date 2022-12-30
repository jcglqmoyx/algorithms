#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int openLock(vector<string> &deadends, string target) {
        string start = "0000";
        if (target == start) return 0;
        unordered_set<string> set(deadends.begin(), deadends.end());
        if (set.count(start)) return -1;
        unordered_map<string, int> dist = {{start, 0}};
        queue<string> q;
        q.push(start);
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                for (int j = -1; j <= 1; j += 2) {
                    string state = t;
                    state[i] = (state[i] - '0' + j + 10) % 10 + '0';
                    if (!dist.count(state) && !set.count(state)) {
                        dist[state] = dist[t] + 1;
                        if (state == target) return dist[state];
                        q.push(state);
                    }
                }
            }
        }
        return -1;
    }
};