class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for (int i = 0; i <= num; i++) {
            int x = i, y = 0;
            while (x) {
                y = y * 10 + x % 10;
                x /= 10;
            }
            if ((i + y) == num) return true;
        }
        return false;
    }
};