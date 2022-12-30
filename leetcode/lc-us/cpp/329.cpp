#include <bits/stdc++.h>

using namespace std;

class Solution {
    int m, n;
    vector<vector<int>> f;
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

    int dp(vector<vector<int>> &matrix, int x, int y) {
        int &v = f[x][y];
        if (v != -1) return v;
        v = 1;
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < m && b >= 0 && b < n && matrix[a][b] > matrix[x][y]) {
                v = max(v, dp(matrix, a, b) + 1);
            }
        }
        return v;
    }

public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        m = (int) matrix.size(), n = (int) matrix[0].size();
        f.resize(m, vector<int>(n, -1));
        int res = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, dp(matrix, i, j));
            }
        }
        return res;
    }
};