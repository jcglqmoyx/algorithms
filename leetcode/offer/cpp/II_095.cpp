#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = (int) text1.size(), m = (int) text2.size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                if (text1[i - 1] == text2[j - 1]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            }
        }
        return f[n][m];
    }
};