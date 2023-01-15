#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &queries) {
        vector<vector<int>> res(n, vector<int>(n));
        int diff[n + 2][n + 2];
        memset(diff, 0, sizeof diff);
        for (auto &q: queries) {
            int x1 = q[0] + 1, y1 = q[1] + 1, x2 = q[2] + 1, y2 = q[3] + 1;
            diff[x1][y1]++;
            diff[x2 + 1][y1]--;
            diff[x1][y2 + 1]--;
            diff[x2 + 1][y2 + 1]++;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
                res[i - 1][j - 1] = diff[i][j];
            }
        }
        return res;
    }
};