class Solution {
public:
    int brokenCalc(int x, int y) {
        if (x >= y) return x - y;
        int step = 0;
        while (y != x) {
            if (y > x) {
                if (y & 1) {
                    y++;
                } else {
                    y /= 2;
                }
            } else {
                return step + x - y;
            }
            step++;
        }
        return step;
    }
};