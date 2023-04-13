#include <bits/stdc++.h>

using namespace std;

class Solution {
    static constexpr int PRIMES[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    static constexpr int MOD = 1e9 + 7, MX = 30, N_PRIMES = 10, M = 1 << N_PRIMES;
public:
    int squareFreeSubsets(vector<int> &nums) {
        int sf2mask[MX + 1]{};
        for (int i = 2; i <= MX; ++i)
            for (int j = 0; j < N_PRIMES; ++j) {
                int p = PRIMES[j];
                if (i % p == 0) {
                    if (i % (p * p) == 0) {
                        sf2mask[i] = 0;
                        break;
                    }
                    sf2mask[i] |= 1 << j;
                }
            }

        int cnt[MX + 1]{}, pow2 = 1;
        for (int x: nums) {
            if (x == 1) pow2 = pow2 * 2 % MOD;
            else ++cnt[x];
        }
        long long f[M]{pow2};
        for (int x = 2; x <= MX; ++x) {
            int mask = sf2mask[x], c = cnt[x];
            if (mask && c) {
                int other = (M - 1) ^ mask, j = other;
                do {
                    f[j | mask] = (f[j | mask] + f[j] * cnt[x]) % MOD;
                    j = (j - 1) & other;
                } while (j != other);
            }
        }
        return accumulate(f, f + M, -1L) % MOD;
    }
};