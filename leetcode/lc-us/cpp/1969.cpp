class Solution {
    using LL = long long;
    constexpr static int MOD = 1e9 + 7;

    static LL fast_power(LL a, LL b) {
        LL res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

public:
    int minNonZeroProduct(int p) {
        LL mx = (1L << p) - 1, x = mx - 1;
        LL res = mx;
        res %= MOD, x %= MOD;
        res = res * fast_power(x, ((1L << p) - 2) / 2) % MOD;
        return (int) res;
    }
};