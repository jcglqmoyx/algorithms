#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int N = 1e5 + 10, M = N << 1, INF = 0x3f3f3f3f;

int h[N], w[N], e[M], ne[M], idx;
LL d1[N], d2[N], up[N];
LL p1[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

LL dfs_d(int u, int father) {
    d1[u] = d2[u] = -INF;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j == father) continue;
        LL t = dfs_d(j, u) + w[u];
        if (t >= d1[u]) {
            d2[u] = d1[u], d1[u] = t;
            p1[u] = j;
        } else if (t > d2[u]) {
            d2[u] = t;
        }
    }
    if (d2[u] == -INF) d2[u] = 0;
    if (d1[u] == -INF) d1[u] = 0;
    d1[u] = max(d1[u], (LL) w[u]);
    return d1[u];
}

void dfs_u(int u, int father) {
    if (father == -1) up[u] = w[u];
    else {
        up[u] = w[u] + up[father];
        if (p1[father] == u) {
            up[u] = max(up[u], d2[father] + w[u]);
        } else {
            up[u] = max(up[u], d1[father] + w[u]);
        }
    }
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j == father) continue;
        dfs_u(j, u);
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
        dfs_d(0, -1);
        dfs_u(0, -1);
        LL res = 0;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 1) {
                res = max(res, d1[i] + up[i] - w[i] * 2);
            }
        }
        return res;
    }
};