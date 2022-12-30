class Solution {
public:
    int convertInteger(int A, int B) {
        int count = 0;
        for (int i = 0; i < 32; i++) {
            count += (A & 1) ^ (B & 1);
            A >>= 1;
            B >>= 1;
        }
        return count;
    }
};