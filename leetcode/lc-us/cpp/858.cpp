class Solution {
    int gcd(int x, int y) {
        return y ? gcd(y, x % y) : x;
    }

public:
    int mirrorReflection(int p, int q) {
        int lcm = p * q / gcd(p, q);
        int x = lcm / q, y = lcm / p;
        if (x & 1) {
            if (y & 1) return 1;
            else return 0;
        }
        return 2;
    }
};