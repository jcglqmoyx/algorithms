#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPyramids(vector<vector<int>> &grid) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        vector<vector<int>> s(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (grid[i - 1][j - 1] == 1) s[i][j] = s[i][j - 1] + 1;
                else s[i][j] = 0;
            }
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 2; j <= m - 1; j++) {
                if (!grid[i - 1][j - 1]) continue;
                for (int k = i - 1; k >= 1; k--) {
                    if (j + i - k <= m && s[k][j + i - k] >= (i - k) * 2 + 1) cnt++;
                    else break;
                }
                for (int k = i + 1; k <= n; k++) {
                    if (j + k - i <= m && s[k][j + k - i] >= (k - i) * 2 + 1) cnt++;
                    else break;
                }
            }
        }
        return cnt;
    }
};