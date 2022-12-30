#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k) {
        int m = (int) mat.size();
        if (m == 0) return {{}};
        int n = (int) mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i - 1 >= 0) dp[i][j] += dp[i - 1][j];
                if (j - 1 >= 0) dp[i][j] += dp[i][j - 1];
                if (i - 1 >= 0 && j - 1 >= 0) dp[i][j] -= dp[i - 1][j - 1];
                dp[i][j] += mat[i][j];
            }
        }
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = dp[i + k >= m ? m - 1 : i + k][j + k >= n ? n - 1 : j + k];
                if (i - k - 1 >= 0 && j - k - 1 >= 0) res[i][j] += dp[i - k - 1][j - k - 1];
                if (j - k - 1 >= 0) res[i][j] -= dp[i + k < m ? i + k : m - 1][j - k - 1];
                if (i - k - 1 >= 0) res[i][j] -= dp[i - k - 1][j + k < n ? j + k : n - 1];
            }
        }
        return res;
    }
};