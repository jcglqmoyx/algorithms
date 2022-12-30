#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeOnes(vector<vector<int>> &grid) {
        int n = (int) grid.size(), m = (int) grid[0].size();

        int S = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    S ^= 1 << (i * m + j);
                }
            }
        }

        if (!S) return 0;
        if (n == 1 || m == 1) return 1;

        int cnt = 0;
        int st[1 << n * m];
        for (int t = S; t; t = (t - 1) & S) {
            st[cnt++] = t;
        }

        int f[1 << n * m];
        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        for (int u = cnt - 1; ~u; u--) {
            int t = st[u];
            for (int i = 0; i < n * m; i++) {
                if (t >> i & 1) {
                    int p = t;
                    int r = i / m, c = i % m;
                    for (int x = 0; x < n; x++) {
                        if (p >> (x * m + c) & 1) {
                            p ^= 1 << (x * m + c);
                        }
                    }
                    for (int y = 0; y < m; y++) {
                        if (p >> (r * m + y) & 1) {
                            p ^= 1 << (r * m + y);
                        }
                    }
                    f[t] = min(f[t], f[p] + 1);
                }
            }
        }
        return f[S];
    }
};