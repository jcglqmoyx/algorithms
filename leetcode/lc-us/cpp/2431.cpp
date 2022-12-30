#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxTastiness(vector<int> &price, vector<int> &tastiness, int maxAmount, int maxCoupons) {
        int n = (int) price.size();
        int f[n + 1][maxAmount + 1][maxCoupons + 1];
        memset(f, 0, sizeof f);
        for (int i = 1; i <= n; i++) {
            int p = price[i - 1], t = tastiness[i - 1];
            for (int j = 0; j <= maxAmount; j++) {
                for (int k = 0; k <= maxCoupons; k++) {
                    f[i][j][k] = f[i - 1][j][k];
                    if (j >= p) f[i][j][k] = max(f[i][j][k], f[i - 1][j - p][k] + t);
                    if (k && j >= p / 2) f[i][j][k] = max(f[i][j][k], f[i - 1][j - p / 2][k - 1] + t);
                }
            }
        }
        return f[n][maxAmount][maxCoupons];
    }
};