#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        const int MOD = 1e9 + 7;
        long long f[goal + 1][n + 1];
        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for (int i = 1; i <= goal; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = (f[i - 1][j - 1] * (n - j + 1) + f[i - 1][j] * max(0, j - k)) % MOD;
            }
        }
        return (int) f[goal][n];
    }
};