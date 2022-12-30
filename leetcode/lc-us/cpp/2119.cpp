class Solution {
public:
    bool isSameAfterReversals(int num) {
        if (!num) return true;
        if (num % 10 == 0) return false;
        return true;
    }
};