#include <bits/stdc++.h>

using namespace std;

class Solution {
    int n;

    bool is_palindrome(const string &s) {
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1]) {
                return false;
            }
        }
        return true;
    }

public:
    int removePalindromeSub(string s) {
        n = (int) s.size();
        if (n <= 1) return n;
        return is_palindrome(s) ? 1 : 2;
    }
};