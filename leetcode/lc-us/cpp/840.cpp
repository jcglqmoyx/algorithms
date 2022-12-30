#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>> &grid) {
        int len = (int) grid.size(), wid = (int) grid[0].size();
        int cnt = 0;
        for (int i = 1; i < len - 1; i++) {
            for (int j = 1; j < wid - 1; j++) {
                if (grid[i][j] == 5) {
                    int map[10] = {0};
                    for (int m = i - 1; m <= i + 1; m++) {
                        for (int n = j - 1; n <= j + 1; n++) {
                            if (grid[m][n] < 1 || grid[m][n] > 9) break;
                            map[grid[m][n]]++;
                        }
                    }
                    bool flag = false;
                    for (int index = 1; index <= 9; index++) {
                        if (map[index] == 0) {
                            flag = true;
                            break;
                        }
                    }
                    if (flag) continue;
                    if (grid[i][j - 1] + grid[i][j + 1] - 10) continue;
                    if (grid[i - 1][j] + grid[i + 1][j] - 10) continue;
                    if (grid[i - 1][j - 1] + grid[i - 1][j] + grid[i - 1][j + 1] - 15) continue;
                    if (grid[i + 1][j - 1] + grid[i + 1][j] + grid[i + 1][j + 1] - 15) continue;
                    if (grid[i - 1][j - 1] + grid[i][j - 1] + grid[i + 1][j - 1] - 15) continue;
                    if (grid[i - 1][j + 1] + grid[i][j + 1] + grid[i + 1][j + 1] - 15) continue;
                    if (grid[i - 1][j - 1] + grid[i + 1][j + 1] - 10) continue;
                    if (grid[i - 1][j + 1] + grid[i + 1][j - 1] - 10) continue;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};