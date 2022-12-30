#include <bits/stdc++.h>

using namespace std;

class Solution {
    int minimum(int a, int b, int c) {
        return min(a, min(b, c));
    }

public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int len = (int) matrix.size(), wid = (int) matrix[0].size();
        int max_side = 0;
        vector<vector<int>> dp(len, vector<int>(wid, 0));
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < wid; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = minimum(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
                    }
                }
                max_side = max(max_side, dp[i][j]);
            }
        }
        return max_side * max_side;
    }
};