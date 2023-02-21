#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int squareFreeSubsets(vector<int> &nums) {
        const int MOD = 1e9 + 7;
        const int N_PRIMES = 10, MX = 30, M = 1 << N_PRIMES;
        int primes[N_PRIMES] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        int mask[31]{};
        for (int i = 2; i <= MX; i++) {
            for (int j = 0; j < N_PRIMES; j++) {
                int x = primes[j];
                if (i % x == 0) {
                    if (i % (x * x) == 0) {
                        mask[i] = -1;
                        break;
                    }
                    mask[i] |= 1 << j;
                }
            }
        }
        int f[M]{1};
        for (int x: nums) {
            if (mask[x] == -1) continue;
            for (int j = M - 1; j >= mask[x]; j--) {
                if ((mask[x] | j) == j) f[j] = (f[j] + f[j ^ mask[x]]) % MOD;
            }
        }
        int res = 0;
        for (int i: f) {
            res = (res + i) % MOD;
        }
        return (res - 1 + MOD) % MOD;
    }
};