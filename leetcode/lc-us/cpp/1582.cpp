#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>> &mat) {
        int n = (int) mat.size(), m = (int) mat[0].size();
        int row[n], col[m];
        memset(row, 0, sizeof row), memset(col, 0, sizeof col);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j]) {
                    row[i]++, col[j]++;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] && row[i] == 1 && col[j] == 1) res++;
            }
        }
        return res;
    }
};