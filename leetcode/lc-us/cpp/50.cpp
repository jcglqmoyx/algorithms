class Solution {
public:
    double quick_mul(double x, long n) {
        double power = 1.0;
        double temp = x;
        while (n) {
            if (n & 1) power *= temp;
            temp *= temp;
            n >>= 1;
        }
        return power;
    }

    double myPow(double x, int n) {
        return n > 0 ? quick_mul(x, (long) n) : 1 / quick_mul(x, -(long) n);
    }
};
