#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int closedIsland(vector<vector<int>> &grid) {
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        int n = (int) grid.size(), m = (int) grid[0].size();
        bool st[n][m];
        memset(st, 0, sizeof st);

        function<bool(int, int)> dfs = [&](int x, int y) -> bool {
            if (x < 0 || x == n || y < 0 || y == m) return false;
            if (grid[x][y] || st[x][y]) return true;
            grid[x][y] = true;
            bool flag = true;
            for (int i = 0; i < 4; i++) {
                if (!dfs(x + dx[i], y + dy[i])) {
                    flag = false;
                }
            }
            return flag;
        };

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!grid[i][j] && !st[i][j]) {
                    if (dfs(i, j)) res++;
                }
            }
        }
        return res;
    }
};