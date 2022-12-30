#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findSquare(vector<vector<int>> &matrix) {
        int n = (int) matrix.size();
        vector<vector<int>> sum(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        int r = -1, c, size = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int len = size + 1; i + len <= n + 1 && j + len <= n + 1; len++) {
                    if (len == 1) {
                        if (matrix[i - 1][j - 1] == 0) {
                            r = i, c = j, size = len;
                        }
                    } else if (len == 2) {
                        if (!matrix[i - 1][j - 1] && !matrix[i - 1][j] && !matrix[i][j - 1] && !matrix[i][j]) {
                            r = i, c = j, size = len;
                        }
                    } else {
                        int x = i + len - 1, y = j + len - 1;
                        int outer = sum[x][y] - sum[x][j - 1] - sum[i - 1][y] + sum[i - 1][j - 1];

                        int i1 = i + 1, j1 = j + 1, x1 = x - 1, y1 = y - 1;
                        int inner = sum[x1][y1] - sum[x1][j1 - 1] - sum[i1 - 1][y1] + sum[i1 - 1][j1 - 1];
                        if (outer - inner == 0) r = i, c = j, size = len;
                    }
                }
            }
        }
        if (r == -1) return {};
        return {r - 1, c - 1, size};
    }
};