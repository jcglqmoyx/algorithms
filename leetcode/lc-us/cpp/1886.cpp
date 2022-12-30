#include <bits/stdc++.h>

using namespace std;

class Solution {
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();
        if (n == 0) return;
        int r = (n >> 1) - 1;
        int c = (n - 1) >> 1;
        for (int i = r; i >= 0; --i) {
            for (int j = c; j >= 0; --j) {
                swap(matrix[i][j], matrix[j][n - i - 1]);
                swap(matrix[i][j], matrix[n - i - 1][n - j - 1]);
                swap(matrix[i][j], matrix[n - j - 1][i]);
            }
        }
    }

public:
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target) {
        for (int i = 0; i < 4; i++) {
            rotate(mat);
            if (mat == target) return true;
        }
        return false;
    }
};