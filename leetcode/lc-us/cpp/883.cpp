#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int projectionArea(vector<vector<int>> &grid) {
        int len = (int) grid.size();
        int projection_area = 0;
        for (int i = 0; i < len; i++) {
            int max_in_row = 0, max_in_col = 0;
            for (int j = 0; j < len; j++) {
                if (grid[i][j]) {
                    projection_area++;
                }
                max_in_row = max(max_in_row, grid[i][j]);
                max_in_col = max(max_in_col, grid[j][i]);
            }
            projection_area += max_in_row + max_in_col;
        }
        return projection_area;
    }
};