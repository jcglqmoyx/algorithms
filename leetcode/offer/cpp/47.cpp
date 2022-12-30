#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>> &grid) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        for (int j = 1; j < m; j++) grid[0][j] += grid[0][j - 1];
        for (int i = 1; i < n; i++) grid[i][0] += grid[i - 1][0];
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                grid[i][j] += max(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[n - 1][m - 1];
    }
};