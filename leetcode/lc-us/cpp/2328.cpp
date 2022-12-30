#include <bits/stdc++.h>

using namespace std;

class Solution {
    using ll = long long;
    const int MOD = 1e9 + 7;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int n, m;
    vector<vector<int>> g;
    ll f[1005][1005];

    ll dp(int x, int y) {
        if (f[x][y] != -1) return (int) f[x][y];
        ll res = 1;
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a == n || b < 0 || b == m || g[a][b] <= g[x][y]) continue;
            res = (res + dp(a, b)) % MOD;
        }
        f[x][y] = res;
        return res;
    }

public:
    int countPaths(vector<vector<int>> &grid) {
        memset(f, -1, sizeof f);
        n = (int) grid.size(), m = (int) grid[0].size(), g = grid;
        ll res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                f[i][j] = dp(i, j);
                res = (res + f[i][j]) % MOD;
            }
        }
        return (int) res;
    }
};