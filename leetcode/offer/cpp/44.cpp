class Solution {
public:
    int findNthDigit(int n) {
        long long s = 9;
        int base = 1, i = 1;
        while (n > i * s) {
            n -= i * s;
            base *= 10;
            s *= 10;
            i++;
        }
        int number = base + (n - 1) / i;
        int r = n % i ? n % i : i;
        for (int j = 0; j < i - r; j++) number /= 10;
        return number % 10;
    }
};