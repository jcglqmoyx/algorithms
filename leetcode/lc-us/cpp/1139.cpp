#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>> &grid) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        int s[n + 1][m + 1];
        memset(s, 0, sizeof s);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + grid[i - 1][j - 1];
            }
        }

        auto get = [&](int x1, int y1, int x2, int y2) {
            return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
        };

        if (!s[n][m]) return 0;
        int max_len = 1;
        for (int i = 1; i <= n - 1; i++) {
            for (int j = 1; j <= m - 1; j++) {
                for (int len = max_len + 1; i + len - 1 <= n && j + len - 1 <= m; len++) {
                    int cnt1 = get(i, j, i + len - 1, j + len - 1);
                    if (len > 2) cnt1 -= get(i + 1, j + 1, i + len - 2, j + len - 2);
                    if (cnt1 == len * 4 - 4) max_len = len;
                }
            }
        }
        return max_len * max_len;
    }
};