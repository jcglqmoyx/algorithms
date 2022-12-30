#include <bits/stdc++.h>

using namespace std;

const int N = 100005, MOD = 1e9 + 7;

int f[N][2][3];

class Solution {
public:
    int checkRecord(int n) {
        memset(f, 0, sizeof f);
        f[0][0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 3; k++) {
                    int cur = f[i][j][k];
                    if (!j) f[i + 1][j + 1][0] = (f[i + 1][j + 1][0] + cur) % MOD;
                    if (k + 1 <= 2) f[i + 1][j][k + 1] = (f[i + 1][j][k + 1] + cur) % MOD;
                    f[i + 1][j][0] = (f[i + 1][j][0] + cur) % MOD;
                }
            }
        }
        int res = 0;
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                res = (res + f[n][j][k]) % MOD;
            }
        }
        return res;
    }
};