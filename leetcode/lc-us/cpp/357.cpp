class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;
        if (n == 2) return 91;
        int prev = 91, count;
        for (int i = 3; i <= n; i++) {
            count = prev;
            int index = 9;
            int number = 9;
            for (int j = 0; j < i - 1; j++) {
                number *= index--;
            }
            count += number;
            prev = count;
        }
        return count;
    }
};