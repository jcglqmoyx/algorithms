#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minTotalDistance(vector<vector<int>> &grid) {
        vector<int> row, col;
        int n = (int) grid.size(), m = (int) grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    row.push_back(i);
                }
            }
        }
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (grid[i][j]) {
                    col.push_back(j);
                }
            }
        }
        int size = (int) row.size();
        int x = row[size / 2], y = col[size / 2];
        int res = 0;
        for (int i = 0; i < size; i++) {
            res += abs(x - row[i]) + abs(y - col[i]);
        }
        return res;
    }
};