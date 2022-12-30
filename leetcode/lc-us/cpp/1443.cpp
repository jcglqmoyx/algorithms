#include <bits/stdc++.h>

using namespace std;

const int N = 100010, M = N << 1;

int h[N], e[M], ne[M], idx;
bool st[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

class Solution {
    int dfs(int u, vector<bool> &has_apple) {
        int sum = 0;
        for (int i = h[u]; i != -1; i = ne[i]) {
            int j = e[i];
            if (!st[j]) {
                st[j] = true;
                auto res = dfs(j, has_apple);
                sum += res;
            }
        }
        if (u && !sum && has_apple[u]) return 2;
        if (sum && u) return sum + 2;
        return sum;
    }

public:
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple) {
        memset(h, -1, sizeof h), idx = 0;
        memset(st, false, sizeof st);
        st[0] = true;
        for (auto &edge: edges) {
            add(edge[0], edge[1]);
            add(edge[1], edge[0]);
        }
        return dfs(0, hasApple);
    }
};