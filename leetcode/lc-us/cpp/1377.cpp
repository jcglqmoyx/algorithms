#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double frogPosition(int n, vector<vector<int>> &edges, int t, int target) {
        vector<double> f(n + 1);
        vector<bool> st(n + 1);
        vector<vector<int>> g(n + 1);
        for (auto &e: edges) g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);
        f[1] = 1.0, st[1] = true;
        if (target == 1) {
            if (!g[target].empty()) return 0;
            return 1;
        }
        queue<int> q;
        q.push(1);
        while (!q.empty() && t--) {
            bool flag = false;
            for (auto it = q.size(); it; it--) {
                auto front = q.front();
                q.pop();
                int cnt = 0;
                for (auto ne: g[front]) {
                    if (!st[ne]) cnt++;
                }
                for (auto ne: g[front]) {
                    if (!st[ne]) {
                        st[ne] = true;
                        f[ne] = f[front] * 1.0 / cnt;
                        if (ne == target) {
                            flag = true;
                            break;
                        }
                        q.push(ne);
                    }
                }
            }
            if (flag) break;
        }
        if (!t) return f[target];
        for (auto ne: g[target]) {
            if (!st[ne]) return 0;
        }
        return f[target];
    }
};