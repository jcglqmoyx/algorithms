class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int res = 0;
        while (target != 1) {
            if (maxDoubles == 0) {
                res += target - 1;
                break;
            } else {
                if (target & 1) {
                    target--;
                } else {
                    target >>= 1;
                    maxDoubles--;
                }
                res++;
            }
        }
        return res;
    }
};