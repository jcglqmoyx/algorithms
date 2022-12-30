#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfGoodPaths(vector<int> &vals, vector<vector<int>> &edges) {
        int n = (int) vals.size();
        vector<vector<int>> g(n);
        for (auto &e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        int p[n];
        iota(p, p + n, 0);
        function<int(int)> find = [&](int x) -> int {
            if (p[x] != x) p[x] = find(p[x]);
            return p[x];
        };
        int v[n];
        iota(v, v + n, 0);
        sort(v, v + n, [&](int i, int j) {
            return vals[i] < vals[j];
        });

        int res = 0;
        unordered_map<int, int> m;
        vector<bool> vis(n);

        for (int i = 0, j = 0; j < n; j++) {
            if (vals[v[j]] != vals[v[i]]) {
                m.clear();
                i = j;
            }
            m[v[j]] = 1;
            vis[v[j]] = true;
            for (int x: g[v[j]]) {
                if (!vis[x]) continue;
                int px = find(x);
                int py = find(v[j]);
                if (px == py) continue;
                res += m[px] * m[py];
                m[py] += m[px];
                p[px] = py;
            }
        }
        return res + n;
    }
};