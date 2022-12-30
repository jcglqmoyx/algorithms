#include <bits/stdc++.h>

using namespace std;

class Solution {
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    int n, m;
    int start_x, start_y;
    unordered_set<string> set;

    void dfs(vector<vector<int>> &g, int x, int y, string &s) {
        g[x][y] = 0;
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a == n || b < 0 || b == m || !g[a][b]) continue;
            s += to_string(a - start_x) + '.' + to_string(b - start_y) + '.';
            dfs(g, a, b, s);
        }
    }

public:
    int numDistinctIslands(vector<vector<int>> &grid) {
        n = (int) grid.size(), m = (int) grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    start_x = i, start_y = j;
                    string s;
                    dfs(grid, i, j, s);
                    set.insert(s);
                }
            }
        }
        return (int) set.size();
    }
};