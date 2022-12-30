#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int m = (int) matrix.size(), n = (int) matrix[0].size();
        vector<int> res(m * n);
        res[0] = matrix[0][0];
        matrix[0][0] = 101;
        int x = 0, y = 0, index = 1;
        while (index < m * n) {
            while (x < n - 1 && matrix[y][x + 1] != 101) {
                res[index++] = matrix[y][++x];
                matrix[y][x] = 101;
            }
            while (y < m - 1 && matrix[y + 1][x] != 101) {
                res[index++] = matrix[++y][x];
                matrix[y][x] = 101;
            }
            while (x >= 1 && matrix[y][x - 1] != 101) {
                res[index++] = matrix[y][--x];
                matrix[y][x] = 101;
            }
            while (y >= 1 && matrix[y - 1][x] != 101) {
                res[index++] = matrix[--y][x];
                matrix[y][x] = 101;
            }
        }
        return res;
    }
};