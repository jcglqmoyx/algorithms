class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        long long num = n;
        int cnt = 0;
        while (num) {
            cnt += (int) (num % 10);
            num /= 10;
        }
        if (cnt <= target) {
            return 0;
        }
        long long tail = 1;
        while (true) {
            long long m = n - n % tail + tail, x = m;
            int t = 0;
            while (x) {
                t += (int) (x % 10);
                x /= 10;
            }
            if (t <= target) {
                return m - n;
            }
            tail *= 10;
        }
    }
};