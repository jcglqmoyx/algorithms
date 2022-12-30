class Solution {
public:
    int waysToStep(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 4;
        long first = 1, second = 2, third = 4, four = 0;
        for (int i = 4; i <= n; i++) {
            four = first + second + third;
            four %= 1000000007;
            first = second;
            second = third;
            third = four;
        }
        return (int) four;
    }
};