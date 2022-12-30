class Solution {
    int MOD = 1000000007;

    long quick_pow(int y) {
        long res = 1;
        long temp = 3;
        while (y) {
            if (y & 1) res = res * temp % MOD;
            temp = temp * temp % MOD;
            y >>= 1;
        }
        return res;
    }

public:
    int cuttingRope(int n) {
        if (n <= 3) return n - 1;
        int quotient = n / 3;
        int mod = n % 3;
        if (mod == 0) {
            return (int) (quick_pow(quotient) % MOD);
        } else if (mod == 1) {
            return (int) (quick_pow(quotient - 1) * 4 % MOD);
        } else {
            return (int) (quick_pow(quotient) * 2 % MOD);
        }
    }
};