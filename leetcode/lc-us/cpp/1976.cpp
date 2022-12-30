#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>> &roads) {
        _roads = roads;
        dijkstra(n);

        vector<vector<int>> g(n);
        for (auto &&r: roads) {
            int x = r[0], y = r[1], z = r[2];
            if (dist[0][x] - dist[0][y] == z) {
                g[y].push_back(x);
            } else if (dist[0][y] - dist[0][x] == z) {
                g[x].push_back(y);
            }
        }
        vector<int> f(n, -1);
        return dfs(g, f, n, 0);
    }

private:
    using LL = long long;

    const int MOD = 1e9 + 7;
    const LL INF = INT64_MAX / 2;
    vector<vector<LL>> dist;
    vector<vector<int>> _roads;

    void dijkstra(int n) {
        vector<bool> st(n);
        dist.resize(n, vector<LL>(n, INF / 2));
        dist[0][0] = 0;
        for (auto &&r: _roads) {
            int x = r[0], y = r[1], z = r[2];
            dist[x][y] = dist[y][x] = z;
        }
        for (int i = 0; i < n; i++) {
            int t = -1;
            for (int j = 0; j < n; j++) {
                if (!st[j] && (t == -1 || dist[0][j] < dist[0][t])) t = j;
            }
            st[t] = true;
            for (int j = 0; j < n; j++) {
                dist[0][j] = min(dist[0][j], dist[0][t] + dist[t][j]);
            }
        }
    }

    int dfs(vector<vector<int>> &g, vector<int> &f, int n, int u) {
        if (u == n - 1) return 1;
        if (f[u] != -1) return f[u];
        f[u] = 0;
        for (int v: g[u]) f[u] = (f[u] + dfs(g, f, n, v)) % MOD;
        return f[u];
    }
};