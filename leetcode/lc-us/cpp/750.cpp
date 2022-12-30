#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countCornerRectangles(vector<vector<int>> &grid) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        if (n < 2 || m < 2) return 0;
        int count = 0;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    for (int k = j + 1; k < m; k++) {
                        if (grid[i][k]) {
                            count += dp[j][k];
                            dp[j][k]++;
                        }
                    }
                }
            }
        }
        return count;
    }
};