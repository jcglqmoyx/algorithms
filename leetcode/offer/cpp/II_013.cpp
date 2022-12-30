#include <bits/stdc++.h>

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        int n = (int) matrix.size(), m = (int) matrix[0].size();
        sum = vector<vector<int>>(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int r1 = row1 + 1, c1 = col1 + 1, r2 = row2 + 1, c2 = col2 + 1;
        return sum[r2][c2] - sum[r1 - 1][c2] - sum[r2][c1 - 1] + sum[r1 - 1][c1 - 1];
    }

private :
    vector<vector<int>> sum;
};