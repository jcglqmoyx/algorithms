#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfWays(int n) {
        const int MOD = 1e9 + 7;
        int f[n + 1];
        memset(f, 0, sizeof f);
        f[0] = f[2] = 1;
        for (int i = 4; i <= n; i++) {
            for (int j = 2; j <= i; j += 2) {
                f[i] = (int) ((f[i] + 1ll * f[j - 2] * f[i - j]) % MOD);
            }
        }
        return f[n];
    }
};