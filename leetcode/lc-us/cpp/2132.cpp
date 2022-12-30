#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool possibleToStamp(vector<vector<int>> &grid, int h, int w) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        int s[n + 1][m + 1], diff[n + 2][m + 2];
        memset(s, 0, sizeof s), memset(diff, 0, sizeof diff);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + grid[i - 1][j - 1];
            }
        }
        for (int i = 1; i + h - 1 <= n; i++) {
            for (int j = 1; j + w - 1 <= m; j++) {
                int cnt = s[i + h - 1][j + w - 1] - s[i + h - 1][j - 1] - s[i - 1][j + w - 1] + s[i - 1][j - 1];
                if (!cnt) {
                    diff[i][j] += 1;
                    diff[i][j + w] -= 1;
                    diff[i + h][j] -= 1;
                    diff[i + h][j + w] += 1;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
                if (!grid[i - 1][j - 1]) {
                    if (!diff[i][j]) return false;
                }
            }
        }
        return true;
    }
};