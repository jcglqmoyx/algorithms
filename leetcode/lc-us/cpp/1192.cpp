#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
int h[N], e[N << 1], ne[N << 1], idx;
int dfn[N], low[N];

class Solution {
private:
    vector<vector<int>> res;

    static void add(int a, int b) {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    void dfs(int u, int p) {
        dfn[u] = low[u] = idx++;
        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            if (j == p) continue;
            if (!dfn[j]) {
                dfs(j, u);
                low[u] = min(low[u], low[j]);
                if (dfn[u] < low[j]) res.push_back({u, j});
            } else {
                low[u] = min(low[u], dfn[j]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections) {
        memset(h, -1, sizeof h), idx = 0;
        memset(dfn, 0, sizeof dfn), memset(low, 0, sizeof low);
        for (auto &edge: connections) {
            int x = edge[0], y = edge[1];
            add(x, y), add(y, x);
        }
        for (int i = 0; i < n; i++) {
            if (!dfn[i]) {
                dfs(i, -1);
            }
        }
        return res;
    }
};