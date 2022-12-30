#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int>> &grid) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        vector<int> res(m);
        for (int i = 0; i < m; i++) {
            int j = i;
            bool valid = true;
            for (int k = 0; k < n; k++) {
                if (grid[k][j] == 1) {
                    if (j < m - 1 && grid[k][j + 1] == 1) {
                        j++;
                    } else {
                        res[i] = -1;
                        valid = false;
                        break;
                    }
                } else {
                    if (j && grid[k][j - 1] == -1) {
                        j--;
                    } else {
                        res[i] = -1;
                        valid = false;
                        break;
                    }
                }
            }
            if (valid) res[i] = j;
        }
        return res;
    }
};