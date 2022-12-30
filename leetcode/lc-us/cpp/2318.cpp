#include <bits/stdc++.h>

using namespace std;

class Solution {
    int get_gcd(int x, int y) {
        if (x % y == 0) return y;
        return get_gcd(y, x % y);
    }

public:
    int distinctSequences(int n) {
        if (n == 1) return 6;
        const int MOD = 1e9 + 7;
        int gcd[6][6];
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                if (i > j) gcd[i][j] = gcd[j][i];
                else gcd[i][j] = get_gcd(i + 1, j + 1);
            }
        }

        int f[n + 1][6][6];
        memset(f, 0, sizeof f);
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                if (i != j && gcd[i][j] == 1) {
                    f[2][i][j] = 1;
                }
            }
        }
        for (int i = 3; i <= n; i++) {
            for (int j = 0; j < 6; j++) {
                for (int k = 0; k < 6; k++) {
                    if (j == k || gcd[j][k] != 1) continue;
                    for (int u = 0; u < 6; u++) {
                        if (u == j || u == k || gcd[u][j] != 1) continue;
                        f[i][j][k] = (f[i][j][k] + f[i - 1][u][j]) % MOD;
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                res = (res + f[n][i][j]) % MOD;
            }
        }
        return res;
    }
};