class Solution {
public:
    int minSteps(int n) {
        int res = 0;
        int d = 2;
        while (n != 1) {
            while (n % d == 0) {
                res += d;
                n /= d;
            }
            d++;
        }
        return res;
    }
};