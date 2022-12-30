class Solution {
public:
    int countHousePlacements(int n) {
        const int MOD = 1e9 + 7;
        long long x = 1, y = 2;
        for (int i = 2; i <= n; i++) {
            long long t = y;
            y += x;
            y %= MOD;
            x = t;
        }
        return (int) (y * y % MOD);
    }
};