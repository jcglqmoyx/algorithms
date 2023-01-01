class Solution {
public:
    int countDigits(int num) {
        int cnt = 0, x = num;
        while (x) {
            if (num % (x % 10) == 0) cnt++;
            x /= 10;
        }
        return cnt;
    }
};