#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>> &land) {
        n = (int) land.size(), m = (int) land[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (land[i][j]) {
                    res.push_back({i, j});
                    r = -1, c = -1;
                    dfs(land, i, j);
                    res.back().push_back(r);
                    res.back().push_back(c);
                }
            }
        }
        return res;
    }

private:
    vector<vector<int>> res;
    int n, m;
    int r, c;

    void dfs(vector<vector<int>> &g, int x, int y) {
        if (x >= 0 && x < n && y >= 0 && y < m && g[x][y]) {
            r = max(r, x), c = max(c, y);
            g[x][y] = 0;
        } else {
            return;
        }
        dfs(g, x + 1, y);
        dfs(g, x - 1, y);
        dfs(g, x, y + 1);
        dfs(g, x, y - 1);
    }
};