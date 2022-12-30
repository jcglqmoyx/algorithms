#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = (int) s1.size(), n = (int) s2.size(), t = (int) s3.size();
        if (m + n - t) return false;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                int p = i + j - 1;
                if (i > 0) {
                    dp[i][j] |= dp[i - 1][j] && s1[i - 1] == s3[p];
                }
                if (j > 0) {
                    dp[i][j] |= dp[i][j - 1] && s2[j - 1] == s3[p];
                }
            }
        }
        return dp[m][n];
    }
};