#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s.empty() && t.empty() || s == t) return false;
        int m = (int) s.size(), n = (int) t.size();
        if (s.empty() && n == 1 || t.empty() || m == 1) return true;
        if (abs(m - n) > 1) return false;
        int i = 0, j = 0;
        while (i < m || j < n) {
            if (s[i] != t[j]) {
                if (i == m - 1 && j == n || i == m && j == n - 1) return true;
                return s.substr(i, m - i) == t.substr(j + 1, n - j - 1) ||
                       s.substr(i + 1, m - i - 1) == t.substr(j, n - j) ||
                       s.substr(i + 1, m - i - 1) == t.substr(j + 1, n - j - 1);
            }
            i++, j++;
        }
        return true;
    }
};