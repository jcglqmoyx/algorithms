#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty()) return s;
        string t(s.rbegin(), s.rend());
        int n = (int) s.size();
        s = s + ' ' + t;
        vector<int> ne(s.size(), -1);
        for (int i = 1, j = -1; i < s.size(); i++) {
            while (j != -1 && s[i] != s[j + 1]) j = ne[j];
            if (s[i] == s[j + 1]) j++;
            ne[i] = j;
        }
        int len = ne[s.size() - 1];
        return s.substr(n + 1, n - len - 1) + s.substr(0, n);
    }
};