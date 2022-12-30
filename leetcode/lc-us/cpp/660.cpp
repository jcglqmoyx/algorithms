class Solution {
public:
    int newInteger(int n) {
        int res = 0, base = 1;
        while (n) {
            res += (n % 9) * base;
            n /= 9;
            if (n) base *= 10;
        }
        return res;
    }
};