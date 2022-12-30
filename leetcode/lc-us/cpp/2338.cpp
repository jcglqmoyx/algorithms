#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int idealArrays(int n, int m) {
        using LL = long long;
        const int MOD = 1e9 + 7;

        int f[m + 1][15];
        memset(f, 0, sizeof f);
        for (int i = 1; i <= m; i++) f[i][1] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j < 14; j++) {
                for (int k = 2; i * k <= m; k++) {
                    f[i * k][j + 1] = (f[i * k][j + 1] + f[i][j]) % MOD;
                }
            }
        }

        int c[n][15];
        memset(c, 0, sizeof c);
        c[0][0] = 1;
        for (int i = 1; i < n; i++) {
            c[i][0] = 1;
            for (int j = 1; j < 15; j++) {
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
            }
        }

        int res = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j < 15; j++) {
                res = (int) ((res + (LL) f[i][j] * c[n - 1][j - 1]) % MOD);
            }
        }
        return res;
    }
};