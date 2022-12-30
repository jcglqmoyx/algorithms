class Solution {
    using LL = long long;
    const int MOD = 1e9 + 7;

    LL quick_pow(LL a, LL b) {
        LL res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

public:
    int countGoodNumbers(long long n) {
        return (int) ((quick_pow(5, (n + 1) / 2) * quick_pow(4, n / 2)) % MOD);
    }
};