#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCost(int maxTime, vector<vector<int>> &edges, vector<int> &passingFees) {
        struct T {
            int p, time, cost;

            bool operator<(const T &t) const {
                return cost > t.cost;
            }
        };

        int n = (int) passingFees.size();
        vector<vector<pair<int, int>>> g(n);
        for (auto &e: edges) {
            int x = e[0], y = e[1], w = e[2];
            g[x].push_back({y, w});
            g[y].push_back({x, w});
        }
        int vis[n];
        memset(vis, 0x3f, sizeof vis);
        vis[0] = 0;
        priority_queue<T> q;
        q.push({0, 0, passingFees[0]});
        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            int p = t.p, time = t.time, cost = t.cost;
            if (p == n - 1) return cost;
            for (auto &ne: g[p]) {
                int x = ne.first, w = ne.second;
                if (time + w > maxTime || time + w >= vis[x]) continue;
                vis[x] = time + w;
                q.push({x, time + w, cost + passingFees[x]});
            }
        }
        return -1;
    }
};