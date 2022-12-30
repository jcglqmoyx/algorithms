#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>> &grid) {
        int res = 0;
        int n = (int) grid.size(), m = (int) grid[0].size();
        vector<vector<int>> s(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + grid[i - 1][j - 1];
                if (grid[i - 1][j - 1]) res = 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (!grid[i - 1][j - 1]) continue;
                for (int len = res + 1; i + len - 1 <= n && j + len - 1 <= m; len++) {
                    int area = s[i + len - 1][j + len - 1]
                               - s[i - 1][j + len - 1] - s[i + len - 1][j - 1]
                               + s[i - 1][j - 1];
                    if (len > 2) {
                        int internal = s[i + len - 2][j + len - 2] - s[i][j + len - 2] - s[i + len - 2][j] + s[i][j];
                        area -= internal;
                    }
                    if (area == (len - 1) * 4) res = max(res, len);
                }
            }
        }
        return res * res;
    }
};