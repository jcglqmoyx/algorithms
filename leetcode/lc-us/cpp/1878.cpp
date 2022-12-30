#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>> &grid) {
        int m = (int) grid.size(), n = (int) grid[0].size();
        int s1[55][55], s2[55][55];
        memset(s1, 0, sizeof s1), memset(s2, 0, sizeof s2);
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                s1[i][j] = s1[i - 1][j - 1] + grid[i - 1][j - 1];
                s2[i][j] = s2[i - 1][j + 1] + grid[i - 1][j - 1];
            }
        }
        vector<int> v;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                v.push_back(grid[i - 1][j - 1]);
                for (int k = 1; i - k >= 1 && i + k <= m && j - k >= 1 && j + k <= n; k++) {
                    int a = s2[i][j - k] - s2[i - k][j];
                    int b = s1[i][j + k] - s1[i - k][j];
                    int c = s2[i + k][j] - s2[i][j + k];
                    int d = s1[i + k][j] - s1[i][j - k];
                    v.push_back(a + b + c + d - grid[i + k - 1][j - 1] + grid[i - k - 1][j - 1]);
                }
            }
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        n = (int) v.size();
        vector<int> res;
        for (int i = n - 1; i >= 0 && n - i <= 3; i--) {
            res.push_back(v[i]);
        }
        return res;
    }
};