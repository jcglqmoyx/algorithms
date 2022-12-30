#include <bits/stdc++.h>

using namespace std;

class Solution {
    using PII = pair<int, int>;
    int n{}, m{};
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
public:
    vector<vector<int>> colorBorder(vector<vector<int>> &grid, int r0, int c0, int color) {
        if (grid[r0][c0] == color) return grid;
        n = (int) grid.size(), m = (int) grid[0].size();
        vector<vector<int>> res = grid;
        vector<PII> internal;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                bool flag = true;
                for (int k = 0; k < 4; k++) {
                    int a = i + dx[k], b = j + dy[k];
                    if (grid[a][b] != grid[i][j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) internal.emplace_back(i, j);
            }
        }
        PII q[n * m + 5];
        int hh = 0, tt = -1;
        int c = res[r0][c0];
        q[++tt] = {r0, c0};
        while (hh <= tt) {
            auto t = q[hh++];
            int x = t.first, y = t.second;
            res[x][y] = color;
            for (int i = 0; i < 4; i++) {
                int a = x + dx[i], b = y + dy[i];
                if (a < 0 || a == n || b < 0 || b == m) continue;
                if (res[a][b] != c) continue;
                q[++tt] = {a, b};
            }
        }
        for (auto &x: internal) {
            res[x.first][x.second] = grid[x.first][x.second];
        }
        return res;
    }
};