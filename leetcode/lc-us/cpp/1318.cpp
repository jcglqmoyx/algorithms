class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        for (int i = 0; i < 32; i++) {
            if (c & 1) {
                if ((a & 1) == 0 && (b & 1) == 0) {
                    flips++;
                }
            } else {
                if (a & 1) flips++;
                if (b & 1) flips++;
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return flips;
    }
};