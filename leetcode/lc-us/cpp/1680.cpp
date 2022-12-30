class Solution {
    static int digit_count(int n) {
        int count = 0;
        while (n) {
            count++;
            n >>= 1;
        }
        return count;
    }

public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;

        long long num = 1;
        for (int i = 2; i <= n; i++) {
            num = (num << digit_count(i)) + i;
            num %= MOD;
        }
        return (int) num;
    }
};