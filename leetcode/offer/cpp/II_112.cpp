#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        n = (int) matrix.size(), m = (int) matrix[0].size();
        f.resize(n, vector<int>(m, -1)), grid = matrix;
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res = max(res, dfs(i, j));
            }
        }
        return res;
    }

private:
    int n, m;
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    vector<vector<int>> f, grid;

    int dfs(int x, int y) {
        int &v = f[x][y];
        if (v != -1) return v;
        v = 1;
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m) continue;
            if (grid[a][b] > grid[x][y]) v = max(v, dfs(a, b) + 1);
        }
        return v;
    }
};