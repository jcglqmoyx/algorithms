#include <bits/stdc++.h>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 1) return dividend;
        if (divisor == -1) return dividend == INT32_MIN ? INT32_MAX : -dividend;
        long a = dividend < 0 ? -(long) dividend : dividend, b = divisor < 0 ? -(long) divisor : divisor;
        bool negative = dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0;
        int quotient = divide(a, b);
        return negative ? -quotient : quotient;
    }

    int divide(long a, long b) {
        if (a < b) return 0;
        int count = 1;
        long temp = b;
        while (a >= (temp << 1)) {
            temp <<= 1;
            count <<= 1;
        }
        return count + divide(a - temp, b);
    }
};