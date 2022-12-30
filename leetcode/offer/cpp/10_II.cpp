class Solution {
public:
    int numWays(int n) {
        if (n == 0) return 1;
        if (n <= 2) return n;
        int first = 1, second = 2, third;
        for (int i = 3; i <= n; i++) {
            third = (first + second) % 1000000007;
            first = second;
            second = third;
        }
        return third;
    }
};