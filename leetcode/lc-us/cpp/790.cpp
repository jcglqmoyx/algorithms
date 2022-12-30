#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numTilings(int n) {
        const int MOD = 1e9 + 7;
        long long f[1001][4];
        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            f[i][0b00] = (f[i][0b00] + f[i - 1][0b00] + f[i - 1][0b11]) % MOD;
            f[i][0b01] = (f[i][0b01] + f[i - 1][0b00] + f[i - 1][0b10]) % MOD;
            f[i][0b10] = (f[i][0b10] + f[i - 1][0b00] + f[i - 1][0b01]) % MOD;
            f[i][0b11] = (f[i][0b11] + f[i - 1][0b00] + f[i - 1][0b01] + f[i - 1][0b10]) % MOD;
        }
        return (int) f[n][0];
    }
};