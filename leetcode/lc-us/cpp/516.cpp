#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = (int) s.size();
        vector<vector<int>> f(n, vector<int>(n));
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (len == 1) f[i][j] = 1;
                else {
                    if (s[i] == s[j]) f[i][j] = f[i + 1][j - 1] + 2;
                    f[i][j] = max(f[i][j], max(f[i + 1][j], f[i][j - 1]));
                }
            }
        }
        return f[0][n - 1];
    }
};