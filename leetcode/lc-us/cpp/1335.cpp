#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDifficulty(vector<int> &jobDifficulty, int d) {
        int n = (int) jobDifficulty.size();
        if (n < d) return -1;
        int f[n + 1][d + 1];
        memset(f, 0x3f, sizeof f);
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= d; j++) {
                int mx = 0;
                for (int k = i - 1; k >= 0; k--) {
                    mx = max(mx, jobDifficulty[k]);
                    f[i][j] = min(f[i][j], f[k][j - 1] + mx);
                }
            }
        }
        return f[n][d];
    }
};