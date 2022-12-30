class Solution {
public:
    int minimumNumbers(int num, int k) {
        if (!num) return 0;
        if (num < k) return -1;
        for (int i = 1; i <= 10; i++) {
            int x = k * i;
            if (x % 10 == num % 10 && k * i <= num) {
                return i;
            }
        }
        return -1;
    }
};