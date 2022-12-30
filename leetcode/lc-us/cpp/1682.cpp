#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = (int) s.size();
        int f[n][n];
        char g[n][n];
        memset(f, 0, sizeof f), memset(g, 0, sizeof g);
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    if (i + 1 == j) f[i][j] = 2;
                    else {
                        if (g[i + 1][j - 1] == s[i]) {
                            f[i][j] = f[i + 1][j - 1];
                        } else {
                            f[i][j] = f[i + 1][j - 1] + 2;
                        }
                    }
                    g[i][j] = s[i];
                } else {
                    f[i][j] = max(f[i + 1][j], f[i][j - 1]);
                    if (f[i + 1][j] > f[i][j - 1]) {
                        g[i][j] = s[j];
                    } else if (f[i + 1][j] < f[i][j - 1]) {
                        g[i][j] = s[i];
                    } else {
                        if (g[i + 1][j] != g[i][j - 1]) {
                            g[i][j] = 0;
                        } else {
                            g[i][j] = g[i + 1][j];
                        }
                    }
                }
            }
        }
        return f[0][n - 1];
    }
};