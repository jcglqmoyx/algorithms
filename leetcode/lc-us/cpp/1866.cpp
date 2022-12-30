#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rearrangeSticks(int n, int k) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> f(n + 1, vector<int>(k + 1));
        f[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                f[i][j] = (int) ((f[i - 1][j - 1] + (long) (i - 1) * f[i - 1][j]) % MOD);
            }
        }
        return f[n][k];
    }
};