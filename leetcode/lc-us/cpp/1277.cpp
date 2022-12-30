#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>> &matrix) {
        int m = (int) matrix.size(), n = (int) matrix[0].size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j]) {
                    if (i == 0 || j == 0) {
                        count++;
                    } else {
                        matrix[i][j] = min(min(matrix[i - 1][j], matrix[i][j - 1]), matrix[i - 1][j - 1]) + 1;
                        count += matrix[i][j];
                    }
                }
            }
        }
        return count;
    }
};