#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int connectTwoGroups(vector<vector<int>> &cost) {
        int n = (int) cost.size(), m = (int) cost[0].size();
        vector<vector<int>> prices(n, vector<int>(1 << m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 1 << m; j++) {
                for (int k = 0; k < m; k++) {
                    if (j >> k & 1) {
                        prices[i][j] += cost[i][k];
                    }
                }
            }
        }
        vector<vector<int>> f(n, vector<int>(1 << m, 1e8));
        for (int j = 0; j < 1 << m; j++) {
            f[0][j] = prices[0][j];
        }
        for (int i = 1; i < n; i++) {
            f[i][0] = 0;
            for (int j = 0; j < 1 << m; j++) {
                for (int k = (j - 1) & j; k; k = (k - 1) & j) {
                    f[i][j] = min(f[i][j], f[i - 1][j ^ k] + prices[i][k]);
                }
                for (int k = 0; k < m; k++) {
                    if (j >> k & 1) {
                        f[i][j] = min(f[i][j], f[i - 1][j] + cost[i][k]);
                    }
                }
            }
        }
        return f[n - 1][(1 << m) - 1];
    }
};