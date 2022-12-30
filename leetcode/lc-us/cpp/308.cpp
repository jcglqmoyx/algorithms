#include <bits/stdc++.h>

using namespace std;

class NumMatrix {
    int n, m;
    vector<vector<int>> tr;

    int low_bit(int x) {
        return x & -x;
    }

    int get(int row, int col) {
        int res = 0;
        while (row) {
            int c = col;
            while (c) {
                res += tr[row][c];
                c -= low_bit(c);
            }
            row -= low_bit(row);
        }
        return res;
    }

public:
    NumMatrix(vector<vector<int>> &matrix) {
        n = (int) matrix.size(), m = (int) matrix[0].size();
        tr = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int r = i + 1, c = j + 1;
                tr[r][c] += matrix[i][j];
                int nr = r + low_bit(r);
                if (nr <= n) {
                    tr[nr][c] += tr[r][c];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int r = i + 1, c = j + 1;
                int nc = c + low_bit(c);
                if (nc <= m) {
                    tr[r][nc] += tr[r][c];
                }
            }
        }
    }

    void update(int x, int y, int val) {
        int add = val - sumRegion(x, y, x, y);
        for (int i = x + 1; i <= n; i += low_bit(i)) {
            for (int j = y + 1; j <= m; j += low_bit(j)) {
                tr[i][j] += add;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++, col1++, row2++, col2++;
        return get(row2, col2) - get(row1 - 1, col2) - get(row2, col1 - 1) + get(row1 - 1, col1 - 1);
    }
};