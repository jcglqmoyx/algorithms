#include <bits/stdc++.h>

using namespace std;

class Solution {
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    int n, m;
    int free, res;
    bool st[20][20];
    vector<vector<int>> g;

    void dfs(int i, int j, int cnt) {
        if (g[i][j] == 2) {
            if (cnt == free) {
                res++;
            } else {
                return;
            }
        }
        st[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int a = i + dx[k], b = j + dy[k];
            if (a < 0 || a == n || b < 0 || b == m || st[a][b] || g[a][b] == -1) continue;
            dfs(a, b, cnt + 1);
        }
        st[i][j] = false;
    }

public:
    int uniquePathsIII(vector<vector<int>> &grid) {
        n = (int) grid.size(), m = (int) grid[0].size();
        free = res = 0, g = grid;
        memset(st, false, sizeof st);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != -1) {
                    free++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j, 1);
                }
            }
        }
        return res;
    }
};