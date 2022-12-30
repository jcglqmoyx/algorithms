#include <bits/stdc++.h>

using namespace std;

class NumMatrix {
    vector<vector<int>> s;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        int len = (int) matrix.size(), wid = (int) matrix[0].size();
        s = vector<vector<int>>(len + 1, vector<int>(wid + 1, 0));
        for (int i = 1; i <= len; i++) {
            s[i][1] = s[i - 1][1] + matrix[i - 1][0];
        }
        for (int j = 1; j <= wid; j++) {
            s[1][j] = s[1][j - 1] + matrix[0][j - 1];
        }
        for (int i = 2; i <= len; i++) {
            for (int j = 2; j <= wid; j++) {
                s[i][j] = s[i - 1][j] + s[i][j - 1] + matrix[i - 1][j - 1] - s[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return s[row2 + 1][col2 + 1] - s[row2 + 1][col1] - s[row1][col2 + 1] + s[row1][col1];
    }
};