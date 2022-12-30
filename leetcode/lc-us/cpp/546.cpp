#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeBoxes(vector<int> &boxes) {
        int n = (int) boxes.size(), f[n][n][n + 1], g[n][n];
        memset(f, -0x3f, sizeof f), memset(g, -0x3f, sizeof g);
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                for (int k = 1; k <= len; k++) {
                    if (len == 1) f[i][j][k] = 1;
                    else if (k == 1) f[i][j][k] = 1 + g[i + 1][j];
                    else {
                        for (int u = i + 1; j - u + 1 >= k - 1; u++) {
                            if (boxes[i] != boxes[u]) continue;
                            int t = 0;
                            if (i + 1 <= u - 1) t = g[i + 1][u - 1];
                            f[i][j][k] = max(f[i][j][k], t + f[u][j][k - 1] - (k - 1) * (k - 1) + k * k);
                        }
                    }
                    g[i][j] = max(g[i][j], f[i][j][k]);
                }
            }
        }
        return g[0][n - 1];
    }
};