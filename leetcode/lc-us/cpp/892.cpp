#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int surfaceArea(vector<vector<int>> &grid) {
        int count_cubes = 0, overlap = 0;
        for (const vector<int> &cubes: grid) {
            for (int cube: cubes) {
                count_cubes += cube;
                overlap += max(cube - 1, 0);
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size() - 1; j++) {
                overlap += min(grid[i][j], grid[i][j + 1]);
            }
        }
        for (int i = 0; i < grid.size() - 1; i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                overlap += min(grid[i][j], grid[i + 1][j]);
            }
        }
        return count_cubes * 6 - overlap * 2;
    }
};