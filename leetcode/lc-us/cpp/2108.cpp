#include <bits/stdc++.h>

using namespace std;

class Solution {
    static bool check(string &s) {
        int n = (int) s.size();
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }

public:
    string firstPalindrome(vector<string> &words) {
        for (auto &s: words) {
            if (check(s)) return s;
        }
        return "";
    }
};