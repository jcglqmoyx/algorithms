#include <bits/stdc++.h>

using namespace std;

class Solution {
    int dp(vector<int> v) {
        int n = (int) v.size(), m = (n + 1) / 3;
        vector<vector<int>> f(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int t = 0;
                if (i >= 2) t = f[i - 2][j - 1];
                f[i][j] = max(f[i][j], max(f[i - 1][j], t + v[i - 1]));
            }
        }
        return f[n][m];
    }

public:
    int maxSizeSlices(vector<int> &slices) {
        return max(dp(vector<int>(slices.begin(), slices.end() - 1)),
                   dp(vector<int>(slices.begin() + 1, slices.end())));
    }
};