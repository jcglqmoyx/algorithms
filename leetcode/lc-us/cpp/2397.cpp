#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumRows(vector<vector<int>> &mat, int cols) {
        int n = (int) mat.size(), m = (int) mat[0].size();
        int res = 0;
        for (int i = 0; i < 1 << m; i++) {
            if (__builtin_popcount(i) != cols) {
                continue;
            }
            bool st[n][m];
            memset(st, 0, sizeof st);
            for (int j = 0; j < m; j++) {
                if (i >> j & 1) {
                    for (int r = 0; r < n; r++) {
                        st[r][j] = true;
                    }
                }
            }
            int cnt = 0;
            for (int r = 0; r < n; r++) {
                bool flag = true;
                for (int c = 0; c < m; c++) {
                    if (mat[r][c] == 1 && !st[r][c]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) cnt++;
            }
            res = max(res, cnt);
        }
        return res;
    }
};