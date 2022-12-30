class Solution {
public:
    int lastRemaining(int n) {
        int step = 1, start = 1;
        bool lr = true;
        while (n > 1) {
            if (lr || (n & 1)) {
                start += step;
            }
            n >>= 1;
            step <<= 1;
            lr = !lr;
        }
        return start;
    }
};