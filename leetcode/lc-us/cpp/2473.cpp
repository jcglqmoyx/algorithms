#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<long long> minCost(int n, vector<vector<int>> &roads, vector<int> &appleCost, int k) {
        using LL = long long;

        vector<LL> res(n);

        int dist[n][n];
        memset(dist, 0x3f, sizeof dist);

        int m = (int) roads.size();
        int h[n], e[m << 1], ne[m << 1], idx = 0;
        memset(h, -1, sizeof h);

        auto add = [&](int a, int b) {
            e[idx] = b, ne[idx] = h[a], h[a] = idx++;
        };

        for (auto &r: roads) {
            int x = r[0] - 1, y = r[1] - 1, cost = r[2];
            dist[x][y] = dist[y][x] = cost;
            add(x, y), add(y, x);
        }

        bool st[n];
        int f[n];
        function<void(int)> dijkstra = [&](int start) {
            memset(st, 0, sizeof st);
            memset(f, 0x3f, sizeof f);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> heap;
            heap.push({0, start});
            f[start] = 0;
            while (!heap.empty()) {
                auto t = heap.top();
                heap.pop();
                if (st[t.second]) continue;
                st[t.second] = true;
                for (int i = h[t.second]; ~i; i = ne[i]) {
                    int x = e[i];
                    if (f[x] > f[t.second] + dist[t.second][x]) {
                        f[x] = f[t.second] + dist[t.second][x];
                        heap.push({f[x], x});
                    }
                }
            }
        };

        for (int i = 0; i < n; i++) {
            LL mn = INT64_MAX;
            dijkstra(i);
            for (int j = 0; j < n; j++) {
                mn = min(mn, appleCost[j] + (LL) (k + 1) * f[j]);
            }
            res[i] = mn;
        }
        return res;
    }
};