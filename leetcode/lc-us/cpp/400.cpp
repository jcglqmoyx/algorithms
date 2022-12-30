class Solution {
public:
    int findNthDigit(int n) {
        if (n < 10) return n;
        long long i = 1, s = 9;
        int base = 1;
        while (n > i * s) {
            n -= (int) (i * s);
            base *= 10;
            s *= 10;
            i++;
        }
        int r = n % i == 0 ? (int) i : (int) (n % i);
        int number = (int) (base + (n + 1) / i - 1);
        for (int j = 0; j < i - r; j++) {
            number /= 10;
        }
        return number % 10;
    }
};