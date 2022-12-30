#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>> &grid) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        int f1 = 0, f2 = 0, idx1 = -1;
        for (int i = 0; i < n; i++) {
            int g1 = INT32_MAX, g2 = INT32_MAX, index1 = 0;
            for (int j = 0; j < m; j++) {
                int t;
                if (idx1 != j) {
                    t = f1 + grid[i][j];
                } else {
                    t = f2 + grid[i][j];
                }
                if (t < g2) {
                    if (t < g1) {
                        g2 = g1;
                        g1 = t;
                        index1 = j;
                    } else {
                        g2 = t;
                    }
                }
            }
            f1 = g1, f2 = g2, idx1 = index1;
        }
        return f1;
    }
};