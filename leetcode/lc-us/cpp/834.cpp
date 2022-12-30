#include <bits/stdc++.h>

using namespace std;

const int N = 3e4 + 5, M = N << 1;

int tot;
int h[N], e[M], ne[M], idx;
int down[N], up[N], cnt[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs1(int u, int father) {
    down[u] = 0, cnt[u] = 1;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j == father) continue;
        dfs1(j, u);
        down[u] += down[j] + cnt[j];
        cnt[u] += cnt[j];
    }
}

void dfs2(int u, int father) {
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j == father) continue;
        up[j] = up[u] + down[u] - (down[j] + cnt[j]) + tot - cnt[j];
        dfs2(j, u);
    }
}

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
        tot = n;
        memset(h, -1, sizeof h), idx = 0;
        for (auto &edge: edges) {
            int a = edge[0], b = edge[1];
            add(a, b), add(b, a);
        }
        dfs1(0, -1);
        dfs2(0, -1);
        vector<int> res(n);
        for (int i = 0; i < n; i++) res[i] = down[i] + up[i];
        return res;
    }
};