#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsCycle(vector<vector<char>> &grid) {
        res = false, n = (int) grid.size(), m = (int) grid[0].size(), g = grid, st.resize(n, vector<bool>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!st[i][j]) {
                    dfs(i, j, -1, -1, g[i][j], 1);
                }
            }
        }
        return res;
    }

private:
    bool res;
    int n, m;
    vector<vector<char>> g;
    vector<vector<bool>> st;
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

    void dfs(int x, int y, int i, int j, char ch, int step) {
        if (x < 0 || x == n || y < 0 || y == m) return;
        if (g[x][y] != ch) return;
        if (st[x][y]) {
            if (g[x][y] == ch && step >= 4) res = true;
            return;
        }
        st[x][y] = true;
        for (int idx = 0; idx < 4; idx++) {
            int a = x + dx[idx], b = y + dy[idx];
            if (!(a == i && b == j)) dfs(a, b, x, y, ch, step + 1);
        }
    }
};