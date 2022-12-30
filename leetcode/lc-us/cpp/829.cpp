class Solution {
public:
    int consecutiveNumbersSum(int n) {
        if (n == 1) return 1;
        int res = 1;
        if (n & 1) res++;
        for (int i = 3; i + i * (i - 1) / 2 <= n; i++) {
            int num = i * (i - 1) / 2;
            if ((n - num) % i == 0) res++;
        }
        return res;
    }
};