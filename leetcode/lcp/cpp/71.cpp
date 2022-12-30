#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reservoir(vector<string> &shape) {
        int n = (int) shape.size(), m = (int) shape[0].size(), c = 1;
        int u[n + 1][m + 2], d[n + 1][m + 2], l[n + 1][m + 2], r[n + 1][m + 2];
        memset(u, 0, sizeof u);
        memset(d, 0, sizeof d);
        memset(l, 0, sizeof l);
        memset(r, 0, sizeof r);
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= m; j++) {
                u[i][j] = c++, d[i][j] = c++, l[i][j] = c++, r[i][j] = c++;
            }
        }

        int fa[c];
        iota(fa, fa + c, 0);
        function<int(int)> find = [&](int x) -> int {
            return fa[x] == x ? x : fa[x] = find(fa[x]);
        };
        auto merge = [&](int x, int y) { fa[find(x)] = find(y); };
        bool ok[c];
        memset(ok, 0, sizeof(ok));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j <= m; j++) merge(r[i][j], l[i][j + 1]);
            for (int j = 1; j <= m; j++) {
                merge(d[i][j], u[i + 1][j]);
                if (shape[i][j - 1] == '.') merge(l[i][j], u[i][j]), merge(l[i][j], d[i][j]), merge(l[i][j], r[i][j]);
                else if (shape[i][j - 1] == 'l') merge(l[i][j], d[i][j]), merge(r[i][j], u[i][j]);
                else merge(l[i][j], u[i][j]), merge(r[i][j], d[i][j]);
            }
            for (int j = 1; j <= m; j++) {
                ok[l[i][j]] = find(l[i][j]) != find(0);
                ok[r[i][j]] = find(r[i][j]) != find(0);
                ok[u[i][j]] = find(u[i][j]) != find(0);
                ok[d[i][j]] = find(d[i][j]) != find(0);
            }
        }
        for (int j = 1; j <= m; j++) {
            merge(u[0][j], 0);
        }
        int ans = 0;
        for (int i = 0; i < c; i++) {
            ans += ok[i] && find(i) == find(0);
        }
        return ans / 2;
    }
};