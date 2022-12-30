class Solution {
public:
    bool isPerfectSquare(int num) {
        long low = 1, high = num;
        while (low < high) {
            long mid = low + (high - low) / 2;
            long product = mid * mid;
            if (product == num) {
                return true;
            } else if (product > num) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low * low == num;
    }
};