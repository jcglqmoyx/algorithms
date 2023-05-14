#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MOD = 1e9 + 7;
        if (zero > one) swap(zero, one);
        int f[high + 1];
        memset(f, 0, sizeof f);
        f[0] = 1;
        for (int i = zero; i <= high; i++) {
            f[i] = f[i - zero];
            if (i >= one) f[i] = (f[i] + f[i - one]) % MOD;
        }
        int res = 0;
        for (int i = low; i <= high; i++) res = (res + f[i]) % MOD;
        return res;
    }
};