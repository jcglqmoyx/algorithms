#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int tallestBillboard(vector<int> &rods) {
        int n = (int) rods.size();
        int m = accumulate(rods.begin(), rods.end(), 0);
        int f[n + 1][m * 2 + 1];
        memset(f, -0x3f, sizeof f);
        f[0][m] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m * 2; j++) {
                int x = rods[i - 1];
                f[i][j] = f[i - 1][j];
                if (j >= x) f[i][j] = max(f[i][j], f[i - 1][j - x] + x);
                if (j + x <= m * 2) f[i][j] = max(f[i][j], f[i - 1][j + x]);
            }
        }
        return f[n][m];
    }
};