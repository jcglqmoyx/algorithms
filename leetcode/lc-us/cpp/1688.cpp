class Solution {
public:
    int numberOfMatches(int n) {
        int match = 0;
        while (n > 1) {
            match += n / 2;
            match += n % 2 == 0 ? 0 : 1;
            n >>= 1;
        }
        return match;
    }
};