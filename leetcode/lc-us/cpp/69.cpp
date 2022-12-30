class Solution {
public:
    int mySqrt(int x) {
        long low = 0, high = x;
        while (low < high) {
            long mid = low + (high - low) / 2;
            if (mid * mid <= x && mid * mid + 2 * mid + 1 > x) {
                return (int) mid;
            } else if (mid * mid > x) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return (int) low;
    }
};