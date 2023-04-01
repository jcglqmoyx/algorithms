#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>> &edges) {
        const int INF = 0x3f3f3f3f;
        int res = INF;
        vector<unordered_set<int>> g(n);
        for (auto &e: edges) {
            int x = e[0], y = e[1];
            g[x].insert(y);
            g[y].insert(x);
        }

        for (auto &e: edges) {
            int x = e[0], y = e[1];
            g[x].erase(y);
            g[y].erase(x);

            int dist[1005];
            memset(dist, 0x3f, sizeof dist);
            dist[x] = 0;
            queue<int> q;
            q.push(x);
            int d = 0;
            while (!q.empty()) {
                d++;
                for (auto it = q.size(); it; it--) {
                    auto t = q.front();
                    q.pop();
                    for (int x: g[t]) {
                        if (dist[x] == INF) {
                            dist[x] = dist[t] + 1;
                            q.push(x);
                        }
                    }
                }
            }
            if (dist[y] != INF) res = min(res, dist[y] + 1);

            g[x].insert(y);
            g[y].insert(x);
        }
        return res == INF ? -1 : res;
    }
};