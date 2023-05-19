#include <bits/stdc++.h>

using namespace std;
const int N = 105, M = N * N / 2;

int h[N], e[M], ne[M], idx;
int color[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int u, int c) {
    color[u] = c;
    for (int i = h[u]; ~i; i = ne[i]) {
        if (!color[e[i]]) {
            if (!dfs(e[i], 3 - c)) {
                return false;
            }
        } else if (color[e[i]] == c) {
            return false;
        }
    }
    return true;
}

class Solution {
public:
    bool isBipartite(vector<vector<int>> &graph) {
        memset(h, -1, sizeof h), idx = 0;
        memset(color, 0, sizeof color);
        int n = (int) graph.size();
        for (int i = 0; i < n; i++) {
            for (int x: graph[i]) {
                add(i, x);
            }
        }
        for (int i = 0; i < n; i++) {
            if (!color[i]) {
                if (!dfs(i, 1)) return false;
            }
        }
        return true;
    }
};