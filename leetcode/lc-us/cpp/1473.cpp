#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target) {
        const int INF = 0x3f3f3f3f;
        int f[m][target + 1][n];
        memset(f, 0x3f, sizeof(f));
        if (!houses[0]) {
            for (int i = 0; i < n; i++) {
                f[0][1][i] = cost[0][i];
            }
        } else {
            f[0][1][houses[0] - 1] = 0;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j <= min(target, i + 1); j++) {
                if (houses[i]) {
                    for (int k = 0; k < n; k++) {
                        if (k == houses[i] - 1) {
                            f[i][j][houses[i] - 1] = min(f[i][j][houses[i] - 1], f[i - 1][j][k]);
                        } else {
                            f[i][j][houses[i] - 1] = min(f[i][j][houses[i] - 1], f[i - 1][j - 1][k]);
                        }
                    }
                } else {
                    for (int k = 0; k < n; k++) {
                        for (int u = 0; u < n; u++) {
                            if (u == k) f[i][j][k] = min(f[i][j][k], f[i - 1][j][u] + cost[i][k]);
                            else f[i][j][k] = min(f[i][j][k], f[i - 1][j - 1][u] + cost[i][k]);
                        }
                    }
                }
            }
        }
        int res = INF;
        for (int i = 0; i < n; i++) {
            res = min(res, f[m - 1][target][i]);
        }
        if (res == INF) return -1;
        else return res;
    }
};