#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid) {
        int increase = 0;
        vector<int> horizontal_max(grid.size()), vertical_max(grid[0].size());
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                horizontal_max[i] = max(horizontal_max[i], grid[i][j]);
                vertical_max[j] = max(vertical_max[j], grid[i][j]);
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                increase += min(horizontal_max[i], vertical_max[j]) - grid[i][j];
            }
        }
        return increase;
    }
};