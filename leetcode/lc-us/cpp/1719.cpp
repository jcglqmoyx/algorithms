#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int checkWays(vector<vector<int>> &pairs) {
        int mx = 0;
        for (auto &p: pairs) mx = max(mx, max(p[0], p[1]));

        int deg[mx + 1];
        bool g[mx + 1][mx + 1];
        memset(deg, 0, sizeof deg), memset(g, false, sizeof g);
        for (auto &p: pairs) {
            g[p[0]][p[1]] = g[p[1]][p[0]] = true;
            deg[p[0]]++, deg[p[1]]++;
        }

        int nodes[mx + 1], n = 0;
        for (int i = 1; i <= mx; ++i) if (deg[i]) nodes[n++] = i;

        sort(nodes, nodes + n, [&](int a, int b) {
            return deg[a] > deg[b];
        });

        if (deg[nodes[0]] != n - 1) return 0;

        int fa[mx + 1];
        bool all_fa[mx + 1][mx + 1];
        memset(fa, 0, sizeof fa), memset(all_fa, false, sizeof all_fa);
        for (int i = 0; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (g[nodes[i]][nodes[j]]) {
                    fa[nodes[i]] = nodes[j];
                    for (int f = nodes[j]; f; f = fa[f]) all_fa[nodes[i]][f] = true;
                    break;
                }
            }
        }

        int res = 1;
        for (int i = 1; i <= mx; ++i) {
            for (int j = i + 1; j <= mx; ++j) {
                if (g[i][j] && deg[i] == deg[j]) res = 2;
                if (g[i][j] != (all_fa[i][j] || all_fa[j][i])) return 0;
            }
        }
        return res;
    }
};