#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>> &prices) {
        using LL = long long;
        int pr[m + 1][n + 1];
        memset(pr, 0, sizeof pr);
        for (auto &p: prices) {
            pr[p[0]][p[1]] = p[2];
        }
        LL f[m + 1][n + 1];
        memset(f, 0, sizeof f);
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = pr[i][j];
                for (int k = 1; k < i; k++) {
                    f[i][j] = max(f[i][j], f[k][j] + f[i - k][j]);
                }
                for (int k = 1; k < j; k++) {
                    f[i][j] = max(f[i][j], f[i][k] + f[i][j - k]);
                }
            }
        }
        return f[m][n];
    }
};