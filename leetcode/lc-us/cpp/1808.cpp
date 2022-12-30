class Solution {
public:
    int maxNiceDivisors(int primeFactors) {
        if (primeFactors == 1) return 1;
        int quotient = primeFactors / 3;
        int remainder = primeFactors % 3;
        if (remainder == 0) {
            return (int) (quick_power(3, quotient) % MOD);
        } else if (remainder == 1) {
            return (int) (quick_power(3, quotient - 1) * 4 % MOD);
        } else {
            return (int) (quick_power(3, quotient) * 2 % MOD);
        }
    }

private:
    static constexpr int MOD = 1000000007;

    static long quick_power(int x, int N) {
        long ans = 1;
        long x_contribute = x;
        while (N > 0) {
            if (N % 2 == 1) {
                ans *= x_contribute;
                ans %= MOD;
            }
            x_contribute *= x_contribute;
            x_contribute %= MOD;
            N /= 2;
        }
        return ans;
    }
};