#include <bits/stdc++.h>

using namespace std;

class Solution {
    using VI = vector<int>;
    using VVI = vector<vector<int>>;
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>> &mines) {
        VVI grid(n, VI(n, 1));
        for (auto &m: mines) grid[m[0]][m[1]] = 0;
        VVI f(n, VI(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0, s = 0; j < n; j++) {
                if (grid[i][j]) s++; else s = 0;
                f[i][j] = s;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = n - 1, s = 0; j >= 0; j--) {
                if (grid[i][j]) s++; else s = 0;
                f[i][j] = min(f[i][j], s);
            }
        }
        for (int j = 0; j < n; j++) {
            for (int i = 0, s = 0; i < n; i++) {
                if (grid[i][j]) s++; else s = 0;
                f[i][j] = min(f[i][j], s);
            }
        }
        for (int j = 0; j < n; j++) {
            for (int i = n - 1, s = 0; i >= 0; i--) {
                if (grid[i][j]) s++; else s = 0;
                f[i][j] = min(f[i][j], s);
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, f[i][j]);
            }
        }
        return res;
    }
};