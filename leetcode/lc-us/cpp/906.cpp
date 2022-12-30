#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        const int N = 1e9;
        LL start = stoll(left), end = stol(right);
        int res = 0;
        for (int i = 1; i < 100000; i++) {
            string s = to_string(i);
            string t = s;
            reverse(t.begin(), t.end());
            string a = s + t, b = s + t.substr(1);
            LL x = stoll(a), y = stoll(b);
            if (x <= N) {
                LL sqr1 = x * x;
                if (is_palindrome(sqr1) && sqr1 >= start && sqr1 <= end) res++;
            }
            if (y <= N) {
                LL sqr2 = y * y;
                if (is_palindrome(sqr2) && sqr2 >= start && sqr2 <= end) res++;
                if (sqr2 >= end) break;
            }
        }
        return res;
    }

private:
    using LL = long long;

    bool is_palindrome(LL num) {
        string s = to_string(num);
        int n = (int) s.size();
        for (int l = 0, r = n - 1; l < r; l++, r--) {
            if (s[l] != s[r]) return false;
        }
        return true;
    }
};