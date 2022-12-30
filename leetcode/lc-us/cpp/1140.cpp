#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int stoneGameII(vector<int> &piles) {
        int n = (int) piles.size();
        int s[n + 1];
        memset(s, 0, sizeof s);
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + piles[i - 1];
        int f[n + 5][n + 5];
        memset(f, 0, sizeof f);
        for (int i = n; i; i--) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; i + k - 1 <= n && k <= j * 2; k++) {
                    f[i][j] = max(f[i][j], s[n] - s[i - 1] - f[i + k][max(k, j)]);
                }
            }
        }
        return f[1][1];
    }
};