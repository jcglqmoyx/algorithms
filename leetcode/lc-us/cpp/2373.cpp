#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid) {
        int n = (int) grid.size();
        vector<vector<int>> res(n - 2, vector<int>(n - 2));
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                int max = 0;
                for (int r = -1; r <= 1; r++) {
                    for (int c = -1; c <= 1; c++) {
                        max = max > grid[i + r][j + c] ? max : grid[i + r][j + c];
                    }
                }
                res[i - 1][j - 1] = max;
            }
        }
        return res;
    }
};