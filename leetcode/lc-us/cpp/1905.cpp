#include <bits/stdc++.h>

using namespace std;

class Solution {
    typedef vector<vector<int>> VVI;
    int n{}, m{};
    bool flag = true;

    void flood_fill(VVI &grid1, VVI &grid2, int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= m) return;
        if (!grid2[x][y]) return;
        if (grid2[x][y] && !grid1[x][y]) {
            flag = false;
        }
        grid2[x][y] = 0;
        flood_fill(grid1, grid2, x + 1, y);
        flood_fill(grid1, grid2, x - 1, y);
        flood_fill(grid1, grid2, x, y + 1);
        flood_fill(grid1, grid2, x, y - 1);
    }

public:
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
        n = (int) grid1.size(), m = (int) grid1[0].size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] && grid1[i][j]) {
                    flag = true;
                    flood_fill(grid1, grid2, i, j);
                    if (flag) res++;
                }
            }
        }
        return res;
    }
};