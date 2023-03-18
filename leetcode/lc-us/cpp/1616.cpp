#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        return can_form_palindrome(a, b) || can_form_palindrome(b, a);
    }

private:
    static bool can_form_palindrome(string &a, string &b) {
        int n = (int) a.size();
        int l = (n - 1) / 2, r = n / 2;
        while (l >= 0) {
            if (a[l] == a[r]) l--, r++;
            else break;
        }
        if (l < 0) return true;
        return valid(a, b, l, r);
    }

    static bool valid(string &a, string &b, int l, int r) {
        bool flag = true;
        for (int i = l, j = r; i >= 0; i--, j++) {
            if (a[i] != b[j]) {
                flag = false;
                break;
            }
        }
        if (flag) return true;
        flag = true;
        for (int i = l, j = r; i >= 0; i--, j++) {
            if (b[i] != a[j]) {
                flag = false;
                break;
            }
        }
        return flag;
    }
};