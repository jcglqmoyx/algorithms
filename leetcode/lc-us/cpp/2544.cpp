class Solution {
public:
    int alternateDigitSum(int n) {
        int res = 0, sign = 1;
        while (n) {
            res += sign * (n % 10);
            n /= 10;
            sign = -sign;
        }
        return res * -sign;
    }
};