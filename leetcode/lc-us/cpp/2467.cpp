#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &amount) {
        int n = (int) amount.size();
        vector<vector<int>> g(n);
        for (auto &e: edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        int p[n];
        function<void(int, int)> dfs1 = [&](int u, int parent) {
            p[u] = parent;
            for (int x: g[u]) {
                if (x == parent) continue;
                dfs1(x, u);
            }
        };
        dfs1(0, -1);

        int f1[n];
        memset(f1, 0, sizeof f1);
        for (int step = 1; bob != -1; step++) {
            f1[bob] = step;
            bob = p[bob];
        }

        bool st[n];
        memset(st, false, sizeof st);
        int res = INT32_MIN;
        function<void(int, int, int)> dfs2 = [&](int u, int step, int w) {
            st[u] = true;
            int v = amount[u];
            if (step == f1[u]) v /= 2;
            else if (f1[u] && f1[u] < step) v = 0;
            bool flag = true;
            for (int x: g[u]) {
                if (st[x]) continue;
                dfs2(x, step + 1, w + v);
                flag = false;
            }
            if (flag) res = max(res, w + v);
        };
        dfs2(0, 1, 0);
        return res;
    }
};