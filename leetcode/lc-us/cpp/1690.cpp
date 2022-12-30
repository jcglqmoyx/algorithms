#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int stoneGameVII(vector<int> &stones) {
        int n = (int) stones.size();
        vector<int> sum(n + 1);
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + stones[i - 1];
        vector<vector<int>> f(n + 1, vector<int>(n + 1));
        for (int len = 2; len <= n; len++) {
            for (int i = 1; i + len - 1 <= n; i++) {
                int j = i + len - 1;
                f[i][j] = max(sum[j] - sum[i] - f[i + 1][j], sum[j - 1] - sum[i - 1] - f[i][j - 1]);
            }
        }
        return f[1][n];
    }
};