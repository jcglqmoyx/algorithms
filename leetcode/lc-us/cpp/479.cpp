#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;
        int mx = (int) pow(10, n) - 1;
        for (int i = mx;; i--) {
            string a = to_string(i), b = a;
            reverse(b.begin(), b.end());
            long long num = stoll(a + b);
            for (int j = mx; (long long) j * j > num; j--) {
                if (num % j == 0) {
                    return (int) (num % 1337);
                }
            }
        }
    }
};