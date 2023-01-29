class Solution {
    using LL = long long;
    const int mod = 1e9 + 7;

    LL quick_power(LL a, int b) {
        LL res = 1;
        while (b) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }

public:
    int monkeyMove(int n) {
        return (int) ((quick_power(2, n) - 2 + mod) % mod);
    }
};