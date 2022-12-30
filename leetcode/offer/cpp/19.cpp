#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = (int) s.size(), m = (int) p.size();
        s = ' ' + s, p = ' ' + p;
        vector<vector<int>> f(n + 1, vector<int>(m + 1));
        f[0][0] = true;
        for (int i = 0; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (j + 1 <= m && p[j + 1] == '*') continue;
                if (p[j] == '*') f[i][j] = f[i][j - 2] || i && f[i - 1][j] && (s[i] == p[j - 1] || p[j - 1] == '.');
                else if (i && p[j] != '*') f[i][j] = f[i - 1][j - 1] && (s[i] == p[j] || p[j] == '.');
            }
        }
        return f[n][m];
    }
};