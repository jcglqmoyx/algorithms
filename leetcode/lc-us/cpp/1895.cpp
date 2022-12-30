#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestMagicSquare(vector<vector<int>> &grid) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        if (n == 1 || m == 1) return 1;
        vector<vector<int>> row(n + 1, vector<int>(m + 1));
        vector<vector<int>> col(n + 1, vector<int>(m + 1));
        vector<vector<int>> s1(n + 2, vector<int>(m + 2));
        vector<vector<int>> s2(n + 2, vector<int>(m + 2));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                row[i][j] += row[i][j - 1] + grid[i - 1][j - 1];
                col[i][j] = col[i - 1][j] + grid[i - 1][j - 1];
                s1[i][j] = s1[i - 1][j - 1] + grid[i - 1][j - 1];
                s2[i][j] = s2[i - 1][j + 1] + grid[i - 1][j - 1];
            }
        }
        int res = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int len = 2; i + len <= n && j + len <= m; len++) {
                    bool flag = true;
                    int sum = -1;
                    for (int row_index = i; row_index <= i + len - 1; row_index++) {
                        if (sum == -1) {
                            sum = row[row_index + 1][j + len] - row[row_index + 1][j];
                        } else {
                            int total = row[row_index + 1][j + len] - row[row_index + 1][j];
                            if (total != sum) {
                                flag = false;
                                break;
                            }
                        }
                    }
                    for (int col_index = j; col_index <= j + len - 1; col_index++) {
                        int total = col[i + len][col_index + 1] - col[i][col_index + 1];
                        if (total != sum) {
                            flag = false;
                            break;
                        }
                    }

                    int x1 = s1[i + len][j + len] - s1[i][j];
                    int x2 = s2[i + len][j + 1] - s2[i][j + len + 1];
                    if (x1 != sum) {
                        flag = false;
                    } else {
                        if (x2 != sum) {
                            flag = false;
                        }
                    }

                    if (flag) {
                        res = max(res, len);
                    }
                }
            }
        }
        return res;
    }
};