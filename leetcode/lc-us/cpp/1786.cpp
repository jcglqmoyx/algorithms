#include <bits/stdc++.h>

using namespace std;

using PII = pair<int, int>;

const int N = 2e4 + 5, M = 8e4 + 5, MOD = 1e9 + 7;

bool st[N];
long long dist[N], f[N];
int h[N], e[M], ne[M], w[M], idx;

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra(int start) {
    memset(dist, 0x3f, sizeof dist);
    dist[start] = 0;
    priority_queue<PII, vector<PII>, greater<>> heap;
    heap.push({0, start});
    while (!heap.empty()) {
        auto t = heap.top();
        heap.pop();
        int u = t.second;
        if (st[u]) continue;
        st[u] = true;
        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[u] + w[i]) {
                dist[j] = dist[u] + w[i];
                heap.push({dist[j], j});
            }
        }
    }
}

class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>> &edges) {
        memset(st, false, sizeof st);
        memset(f, 0, sizeof f);
        memset(h, -1, sizeof h);
        idx = 0;

        for (auto &edge: edges) {
            int x = edge[0], y = edge[1], z = edge[2];
            add(x, y, z), add(y, x, z);
        }
        dijkstra(n);
        vector<PII> v;
        for (int i = 1; i <= n; i++) v.emplace_back(dist[i], i);
        sort(v.begin(), v.end());
        f[n] = 1;
        for (auto &p: v) {
            int d = p.first, u = p.second;
            for (int i = h[u]; ~i; i = ne[i]) {
                int j = e[i];
                if (d < dist[j]) {
                    f[j] = (f[u] + f[j]) % MOD;
                }
            }
        }
        return (int) f[1];
    }
};