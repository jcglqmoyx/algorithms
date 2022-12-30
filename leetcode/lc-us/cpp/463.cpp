#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>> &grid) {
        int perimeter = 0;
        int overlap = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    perimeter += 4;
                    if (i > 0 && grid[i - 1][j] == 1) {
                        overlap++;
                    }
                    if (j > 0 && grid[i][j - 1] == 1) {
                        overlap++;
                    }
                }
            }
        }
        return perimeter - overlap * 2;
    }
};