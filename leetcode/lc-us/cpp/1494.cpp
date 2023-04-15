#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>> &relations, int k) {
        int pre[n];
        memset(pre, 0, sizeof pre);
        for (auto &r: relations) {
            pre[r[1] - 1] |= 1 << (r[0] - 1);
        }
        int f[1 << n];
        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        for (int i = 0; i < 1 << n; i++) {
            int to_study = 0;
            for (int j = 0; j < n; j++) {
                if ((pre[j] & i) == pre[j] && !(i >> j & 1)) {
                    to_study |= 1 << j;
                }
            }
            for (int t = to_study; t; t = (t - 1) & to_study) {
                if (__builtin_popcount(t) <= k) {
                    f[i | t] = min(f[i | t], f[i] + 1);
                }
            }
        }
        return f[(1 << n) - 1];
    }
};