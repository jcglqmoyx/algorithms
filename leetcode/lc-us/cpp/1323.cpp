class Solution {
public:
    int maximum69Number(int num) {
        int cp = num;
        if (num / 1000 == 6) {
            return cp + 3000;
        }
        num %= 1000;
        if (num / 100 == 6) {
            return cp + 300;
        }
        num %= 100;
        if (num / 10 == 6) {
            return cp + 30;
        }
        num %= 10;
        if (num == 6) {
            return cp + 3;
        }
        return cp;
    }
};