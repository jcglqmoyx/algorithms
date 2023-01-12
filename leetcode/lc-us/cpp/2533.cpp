#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int goodBinaryStrings(int minLength, int maxLength, int oneGroup, int zeroGroup) {
        const int MOD = 1e9 + 7;

        function<int(int, int, int)> helper = [](int n, int one_group, int zero_group) -> int {
            int f[n + 1];
            memset(f, 0, sizeof f);
            f[0] = 1;
            int res = 0;
            for (int i = min(one_group, zero_group); i <= n; i++) {
                if (i >= zero_group) f[i] = (f[i] + f[i - zero_group]) % MOD;
                if (i >= one_group) f[i] = (f[i] + f[i - one_group]) % MOD;
                res = (res + f[i]) % MOD;
            }
            return res;
        };
        return (helper(maxLength, oneGroup, zeroGroup) - helper(minLength - 1, oneGroup, zeroGroup) + MOD) % MOD;
    }
};