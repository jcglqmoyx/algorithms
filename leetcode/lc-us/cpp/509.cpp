class Solution {
public:
    int fib(int N) {
        if (N <= 1) {
            return N;
        }
        int first = 0, second = 1, third = 1;
        for (int i = 2; i <= N; i++) {
            third = first + second;
            first = second;
            second = third;
        }
        return third;
    }
};