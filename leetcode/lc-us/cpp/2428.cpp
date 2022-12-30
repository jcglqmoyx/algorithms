#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSum(vector<vector<int>> &g) {
        int n = (int) g.size(), m = (int) g[0].size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i + 2 < n && j + 2 < m) {
                    int s = g[i][j] + g[i][j + 1] + g[i][j + 2] + g[i + 1][j + 1] + g[i + 2][j] + g[i + 2][j + 1] + g[i + 2][j + 2];
                    res = max(res, s);
                }
            }
        }
        return res;
    }
};
