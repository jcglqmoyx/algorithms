#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int N = 1e5 + 10, M = N << 1;

int h[N], w[N], e[M], ne[M], idx;
LL down[N], up[N];
LL parent[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

LL dfs1(int u, int p) {
    parent[u] = p;
    LL dist = 0;
    for (int i = h[u]; ~i; i = ne[i]) {
        if (e[i] != p) dist = max(dist, dfs1(e[i], u));
    }
    down[u] = dist + w[u];
    return down[u];
}

void dfs2(int u, int p) {
    if (p == -1) {
        up[u] = w[u];
    } else {
        up[u] = up[p] + w[u];
        for (int i = h[p]; ~i; i = ne[i]) {
            int j = e[i];
            if (j == parent[p] || j == u) continue;
            up[u] = max(up[u], down[j] + w[p] + w[u]);
        }
    }
    for (int i = h[u]; ~i; i = ne[i]) {
        if (e[i] != p) dfs2(e[i], u);
    }
}

class Solution {
public:
    long long maxOutput(int n, vector<vector<int>> &edges, vector<int> &price) {
        memset(h, -1, sizeof h), idx = 0;
        for (int i = 0; i < n; i++) w[i] = price[i];
        vector<int> deg(n);
        for (auto &edge: edges) {
            int x = edge[0], y = edge[1];
            add(x, y), add(y, x);
            deg[x]++, deg[y]++;
        }
        dfs1(0, -1);
        dfs2(0, -1);
        LL res = 0;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 1) {
                res = max(res, down[i] + up[i] - w[i] * 2);
            }
        }
        return res;
    }
};