#include <bits/stdc++.h>

using namespace std;

using PII = pair<int, int>;

const int N = 3010, M = 20010;

int dist[N];
bool st[N];
int h[N], w[M], e[M], ne[M], idx;

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    memset(st, false, sizeof st);
    dist[0] = 0;
    priority_queue<PII, vector<PII>, greater<>> heap;
    heap.push({0, 0});
    while (!heap.empty()) {
        auto t = heap.top();
        heap.pop();
        int d = t.first, v = t.second;
        if (st[v]) continue;
        st[v] = true;
        for (int i = h[v]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[j] > d + w[i]) {
                dist[j] = d + w[i];
                heap.push({dist[j], j});
            }
        }
    }
}

class Solution {
public:
    int reachableNodes(vector<vector<int>> &edges, int maxMoves, int n) {
        memset(h, -1, sizeof h), idx = 0;
        for (auto &edge: edges) {
            int x = edge[0], y = edge[1], z = edge[2];
            add(x, y, z + 1), add(y, x, z + 1);
        }

        dijkstra();

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (dist[i] <= maxMoves) res++;
        }
        for (auto &edge: edges) {
            int x = edge[0], y = edge[1], z = edge[2];
            int a = max(0, maxMoves - dist[x]), b = max(0, maxMoves - dist[y]);
            res += min(a + b, z);
        }
        return res;
    }
};