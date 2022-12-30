#include <bits/stdc++.h>

const int N = 1010, MOD = 1e9 + 7;

int fact[N], infact[N];

class Solution {
    int quick_power(int a, int b) {
        int res = 1;
        while (b) {
            if (b & 1) {
                res = (int) (1LL * res * a % MOD);
            }
            a = (int) (1LL * a * a % MOD);
            b >>= 1;
        }
        return res;
    }

public:
    int numberOfWays(int startPos, int endPos, int k) {
        int m = abs(startPos - endPos);
        if (k % 2 != m % 2 || m > k) return 0;
        int l = (k - m) / 2;
        fact[0] = infact[0] = 1;
        for (int i = 1; i < N; i++) {
            fact[i] = (int) (1LL * fact[i - 1] * i % MOD);
            infact[i] = quick_power(fact[i], MOD - 2);
        }
        return (int) (1LL * fact[k] * infact[l] % MOD * infact[k - l] % MOD);
    }
};