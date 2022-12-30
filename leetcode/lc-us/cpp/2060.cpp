#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool possiblyEquals(string s1, string s2) {
        int n = (int) s1.size(), m = (int) s2.size(), N = 2000, offset = 1000;
        bool st[n + 1][m + 1][N];
        memset(st, 0, sizeof st);
        function<bool(int, int, int)> dp = [&](int i, int j, int diff) -> bool {
            if (i == n && j == m) return !diff;
            if (st[i][j][diff + offset]) return false;
            st[i][j][diff + offset] = true;
            int a = i, b = j;
            while (a < n && isdigit(s1[a])) {
                int num = stoi(s1.substr(i, a - i + 1));
                if (dp(a + 1, j, diff - num)) return true;
                a++;
            }
            if (diff > 0 && i < n && isalpha(s1[i]) && dp(i + 1, j, diff - 1)) return true;
            while (b < m && isdigit(s2[b])) {
                int num = stoi(s2.substr(j, b - j + 1));
                if (dp(i, b + 1, diff + num)) return true;
                b++;
            }
            if (diff < 0 && j < m && isalpha(s2[j]) && dp(i, j + 1, diff + 1)) return true;
            if (!diff && isalpha(s1[i]) && s1[i] == s2[j]) return dp(i + 1, j + 1, 0);
            return false;
        };
        return dp(0, 0, 0);
    }
};