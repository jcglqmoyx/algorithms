class Solution {
public:
    int countOrders(int n) {
        using LL = long long;
        const int MOD = 1e9 + 7;
        if (n == 1) return 1;
        LL res = 1, prev = 1;
        for (int i = 2; i <= n; i++) {
            int x = i << 1;
            LL sum = (LL) (x - 1) * x / 2;
            res = sum * prev % MOD;
            prev = res;
        }
        return (int) res;
    }
};