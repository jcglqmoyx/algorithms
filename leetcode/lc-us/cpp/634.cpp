class Solution {
public:
    int findDerangement(int n) {
        const int MOD = 1e9 + 7;
        if (n <= 2) return n - 1;
        long long first = 0, second = 1, res;
        for (int i = 3; i <= n; i++) {
            res = (i - 1) * (first + second) % MOD;
            first = second, second = res;
        }
        return (int) res;
    }
};