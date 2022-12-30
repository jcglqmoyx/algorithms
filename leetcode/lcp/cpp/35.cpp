#include <bits/stdc++.h>

using namespace std;

class Solution {
    const int INF = 0x3f3f3f3f;
public:
    int electricCarPlan(vector<vector<int>> &paths, int cnt, int start, int end, vector<int> &charge) {
        int n = (int) charge.size();
        vector<vector<int>> dist(n, vector<int>(cnt + 1, INF));
        dist[start][0] = 0;

        vector<vector<pair<int, int>>> adj(n);
        for (auto &path: paths) {
            int u = path[0], v = path[1], w = path[2];
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(0, start, 0);

        while (!pq.empty()) {
            auto[t, u, c] = pq.top();
            pq.pop();
            if (t > dist[u][c])
                continue;
            if (u == end)
                return t;

            if (c < cnt) {
                int nt = t + charge[u];
                if (nt < dist[u][c + 1]) {
                    dist[u][c + 1] = nt;
                    pq.emplace(nt, u, c + 1);
                }
            }

            for (auto[v, w]: adj[u]) {
                if (c >= w && t + w < dist[v][c - w]) {
                    dist[v][c - w] = t + w;
                    pq.emplace(t + w, v, c - w);
                }
            }
        }
        return -1;
    }
};