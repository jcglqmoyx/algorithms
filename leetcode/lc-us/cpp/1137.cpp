class Solution {
public:
    int tribonacci(int n) {
        if (n <= 1) return n;
        if (n <= 3) return n - 1;
        int first = 1, second = 1, third = 2, fourth = 4;
        for (int i = 4; i <= n; i++) {
            fourth = third + first + second;
            first = second;
            second = third;
            third = fourth;
        }
        return fourth;
    }
};