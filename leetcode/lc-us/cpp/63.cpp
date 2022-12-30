#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        if (obstacleGrid.front().front() == 1) return 0;
        for (int i = 0; i < obstacleGrid.size(); i++) {
            if (obstacleGrid[i][0] != 1) obstacleGrid[i][0] = 1;
            else {
                obstacleGrid[i][0] = 0;
                for (int j = i + 1; j < obstacleGrid.size(); j++) obstacleGrid[j][0] = 0;
                break;
            }
        }
        for (int j = 1; j < obstacleGrid[0].size(); j++) {
            if (obstacleGrid[0][j] != 1) obstacleGrid[0][j] = 1;
            else {
                obstacleGrid[0][j] = 0;
                for (int k = j + 1; k < obstacleGrid[0].size(); k++) obstacleGrid[0][k] = 0;
                break;
            }
        }
        for (int i = 1; i < obstacleGrid.size(); i++) {
            for (int j = 1; j < obstacleGrid[0].size(); j++) {
                if (obstacleGrid[i][j] == 1) obstacleGrid[i][j] = 0;
                else obstacleGrid[i][j] = obstacleGrid[i][j - 1] + obstacleGrid[i - 1][j];
            }
        }
        return obstacleGrid.back().back();
    }
};