int guess(int num);

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return -1 if num is lower than the guess number
 *          1 if num is higher than the guess number
 *          otherwise return 0
 */



class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int result = guess(mid);
            if (result == 0) {
                return mid;
            } else if (result == -1) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};