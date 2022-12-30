#include <bits/stdc++.h>

using namespace std;

class Solution {
    static void flip(vector<vector<int>> &g, int n, int col) {
        for (int i = 0; i < n; i++) {
            g[i][col] ^= 1;
        }
    }

public:
    bool removeOnes(vector<vector<int>> &grid) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        for (int j = 0; j < m; j++) {
            if (grid[0][j]) {
                flip(grid, n, j);
            }
        }
        for (int i = 1; i < n; i++) {
            int count_one = 0;
            for (auto x: grid[i]) {
                if (x) {
                    count_one++;
                }
            }
            if (count_one != 0 && count_one != m) {
                return false;
            }
        }
        return true;
    }
};