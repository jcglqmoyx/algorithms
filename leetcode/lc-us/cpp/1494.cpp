#include <bits/stdc++.h>

using namespace std;

class Solution {
    int f[1 << 15];

    void dfs(int n, int k, int state, int valid, int start, int selected) {
        if (!k || !valid) {
            f[state | selected] = min(f[state | selected], f[state] + 1);
        } else {
            for (int i = start; i < n; i++) {
                if (valid >> i & 1) {
                    dfs(n, k - 1, state, valid ^ 1 << i, i + 1, selected | 1 << i);
                }
            }
        }
    }

public:
    int minNumberOfSemesters(int n, vector<vector<int>> &relations, int k) {
        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        for (auto &r: relations) r[0]--, r[1]--;
        for (int i = 0; i < 1 << n; i++) {
            int invalid = 0;
            for (auto &r: relations) {
                if (!(i >> r[0] & 1)) invalid |= 1 << r[1];
            }
            int valid = 0;
            for (int j = 0; j < n; j++) {
                if (!(i >> j & 1) && !(invalid >> j & 1)) valid |= 1 << j;
            }
            dfs(n, k, i, valid, 0, 0);
        }
        return f[(1 << n) - 1];
    }
};