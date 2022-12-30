#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int x = 0, y = 0;
        matrix[0][0] = 1;
        int total = 1;
        while (total < n * n) {
            while (x < n - 1 && !matrix[y][x + 1]) {
                matrix[y][++x] = ++total;
            }
            while (y < n - 1 && !matrix[y + 1][x]) {
                matrix[++y][x] = ++total;
            }
            while (x >= 1 && !matrix[y][x - 1]) {
                matrix[y][--x] = ++total;
            }
            while (y >= 1 && !matrix[y - 1][x]) {
                matrix[--y][x] = ++total;
            }
        }
        return matrix;
    }
};