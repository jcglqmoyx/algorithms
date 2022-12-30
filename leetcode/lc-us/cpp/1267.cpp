#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>> &grid) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        vector<int> row(n), col(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] && (row[i] > 1 || col[j] > 1)) {
                    count++;
                }
            }
        }
        return count;
    }
};