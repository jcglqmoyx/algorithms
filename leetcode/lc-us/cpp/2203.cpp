#include <bits/stdc++.h>

using namespace std;

class Solution {
    using LL = long long;
    using PII = pair<int, int>;

    const LL INF = INT64_MAX / 3;

    vector<LL> dijkstra(int n, int src1, int src2, int dest, vector<vector<PII>> &g, vector<LL> &dist) {
        vector<bool> st(n);
        dist[src1] = 0;
        priority_queue<PII, vector<PII>, greater<>> heap;
        heap.push({0, src1});
        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            int v = t.second;
            if (st[v]) continue;
            st[v] = true;

            for (auto &ne: g[v]) {
                int j = ne.first, w = ne.second;
                if (dist[j] > dist[v] + ne.second) {
                    dist[j] = dist[v] + ne.second;
                    heap.push({dist[j], j});
                }
            }
        }
        return {dist[src2], dist[dest]};
    }

public:
    long long minimumWeight(int n, vector<vector<int>> &edges, int src1, int src2, int dest) {
        vector<vector<PII>> g1(n), g2(n);
        for (auto &e: edges) {
            int x = e[0], y = e[1], w = e[2];
            g1[x].push_back({y, w});
            g2[y].push_back({x, w});
        }

        vector<LL> dist1(n, INF), dist2(n, INF), dist3(n, INF);
        vector<LL> t1 = dijkstra(n, src1, src2, dest, g1, dist1),
                t2 = dijkstra(n, src2, src1, dest, g1, dist2),
                t3 = dijkstra(n, dest, src1, src2, g2, dist3);


        LL res = t1[1] + t2[1];
        res = min(res, t1[0] + t2[1]);
        res = min(res, t2[0] + t1[1]);

        if (res >= INF) return -1;

        for (int i = 0; i < n; i++) {
            if (dist1[i] == INF) continue;
            if (dist2[i] == INF) continue;
            if (dist3[i] == INF) continue;
            res = min(res, dist1[i] + dist2[i] + dist3[i]);
        }
        return res;
    }
};