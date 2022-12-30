class Solution {
public:
    long long kMirror(int k, int n) {
        using LL = long long;
        int digits[100];

        auto is_palindrome = [&](LL x) {
            int len = 0;
            while (x) {
                digits[len] = (int) (x % k);
                len++;
                x /= k;
            }
            for (int l = 0, r = len - 1; l < r; l++, r--) {
                if (digits[l] != digits[r]) {
                    return false;
                }
            }
            return true;
        };
        LL res = 0;
        int i = 1, count = 0;
        while (count < n) {
            int right = i * 10;
            for (int op = 0; op < 2; op++) {
                for (int left = i; left < right && count < n; left++) {
                    LL x = left;
                    int y = op ? left : left / 10;
                    while (y) {
                        x = x * 10 + y % 10;
                        y /= 10;
                    }
                    if (is_palindrome(x)) count++, res += x;
                }
            }
            i = right;
        }
        return res;
    }
};