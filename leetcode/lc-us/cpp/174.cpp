#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        int n = (int) dungeon.size(), m = (int) dungeon[0].size();
        vector<vector<int>> f(n, vector<int>(m, 1e8));
        for (int i = n - 1; ~i; i--) {
            for (int j = m - 1; ~j; j--) {
                if (i == n - 1 && j == m - 1) {
                    f[i][j] = max(1, 1 - dungeon[i][j]);
                } else {
                    if (i < n - 1) f[i][j] = max(1, f[i + 1][j] - dungeon[i][j]);
                    if (j < m - 1) f[i][j] = max(1, min(f[i][j], f[i][j + 1] - dungeon[i][j]));
                }
            }
        }
        return f[0][0];
    }
};