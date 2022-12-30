class Solution {
public:
    int numOfWays(int n) {
        using LL = long long;
        const int MOD = 1e9 + 7;
        LL f1 = 6, f2 = 6;
        for (int i = 2; i <= n; i++) {
            LL ff1 = (f1 * 2 + f2 * 2) % MOD;
            LL ff2 = (f1 * 2 + f2 * 3) % MOD;
            f1 = ff1, f2 = ff2;
        }
        return (int) ((f1 + f2) % MOD);
    }
};