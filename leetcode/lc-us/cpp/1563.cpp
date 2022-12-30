#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int stoneGameV(vector<int> &stoneValue) {
        int n = (int) stoneValue.size(), sums[n + 1];
        sums[0] = 0;
        for (int i = 0; i < n; ++i) {
            sums[i + 1] = sums[i] + stoneValue[i];
        }

        int dp[n][n], mxl[n][n], mxr[n][n];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            mxl[i][i] = stoneValue[i], mxr[i][i] = stoneValue[i];
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 0, j = i + len - 1, m = 0; j < n; ++i, ++j) {
                while (sums[m + 1] - sums[i] < sums[j + 1] - sums[m + 1]) ++m;
                if (m > i) dp[i][j] = max(dp[i][j], mxl[i][m - 1]);
                if (m < j) dp[i][j] = max(dp[i][j], mxr[m + 1][j]);
                if (sums[m + 1] - sums[i] == sums[j + 1] - sums[m + 1]) {
                    dp[i][j] = max(dp[i][j], mxl[i][m]);
                    dp[i][j] = max(dp[i][j], mxr[m + 1][j]);
                }
                mxl[i][j] = max(mxl[i][j - 1], dp[i][j] + sums[j + 1] - sums[i]);
                mxr[i][j] = max(mxr[i + 1][j], dp[i][j] + sums[j + 1] - sums[i]);
            }
        }
        return dp[0][n - 1];
    }
};