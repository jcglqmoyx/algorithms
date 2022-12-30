#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumTimeRequired(vector<int> &jobs, int k) {
        int n = (int) jobs.size();

        int sum[1 << n];
        memset(sum, 0, sizeof sum);
        for (int i = 1; i < 1 << n; i++) {
            int j = i & (i - 1);
            sum[i] = sum[j] + jobs[__builtin_ctz(i ^ j)];
        }

        int f[k][1 << n];
        memset(f, 0x3f, sizeof f);
        for (int i = 0; i < 1 << n; i++) {
            f[0][i] = sum[i];
        }
        for (int i = 1; i < k; i++) {
            for (int j = 0; j < 1 << n; j++) {
                for (int u = j; u; u = (u - 1) & j) {
                    f[i][j] = min(f[i][j], max(f[i - 1][j - u], sum[u]));
                }
            }
        }

        return f[k - 1][(1 << n) - 1];
    }
};