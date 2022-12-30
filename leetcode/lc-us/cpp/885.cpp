#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> positions;
        int total = rows * cols;
        positions.reserve(total);
        positions.push_back({rStart, cStart});
        int x = rStart, y = cStart;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int direction = 0;
        int step = 1;
        int flag = 0;
        while (positions.size() < total) {
            for (int i = 0; i < step; i++) {
                int nx = x + dx[direction];
                int ny = y + dy[direction];
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                    positions.push_back({nx, ny});
                    if (positions.size() == total) {
                        return positions;
                    }
                }
                x = nx;
                y = ny;
            }
            direction = (direction + 1) % 4;
            flag++;
            if (flag == 2) {
                step++;
                flag = 0;
            }
        }
        return positions;
    }
};