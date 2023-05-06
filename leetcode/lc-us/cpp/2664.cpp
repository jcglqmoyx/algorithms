#include <bits/stdc++.h>

using namespace std;

class Solution {
    int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    bool dfs(vector<vector<int>> &v, int m, int n, int x, int y, int u) {
        if (u == m * n) {
            return true;
        }
        for (int i = 0; i < 8; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= m || b < 0 || b >= n || v[a][b] != -1) continue;
            v[a][b] = u;
            if (dfs(v, m, n, a, b, u + 1)) return true;
            v[a][b] = -1;
        }
        return false;
    }

public:
    vector<vector<int>> tourOfKnight(int m, int n, int r, int c) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        res[r][c] = 0;
        dfs(res, m, n, r, c, 1);
        return res;
    }
};