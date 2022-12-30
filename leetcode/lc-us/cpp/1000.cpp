#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mergeStones(vector<int> &stones, int k) {
        const int INF = 0x3f3f3f3f;
        int n = (int) stones.size();
        if ((n - 1) % (k - 1)) return -1;
        vector<int> sum(n + 1);
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + stones[i - 1];
        vector<vector<int>> f(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) f[i][i] = 0;
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                for (int u = i + 1; u <= j; u += k - 1) {
                    f[i][j] = min(f[i][j], f[i][u - 1] + f[u][j]);
                }
                if ((len - 1) % (k - 1) == 0) {
                    f[i][j] += sum[j + 1] - sum[i];
                }
            }
        }
        return f[0][n - 1];
    }
};