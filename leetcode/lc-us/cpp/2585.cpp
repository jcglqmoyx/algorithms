#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>> &types) {
        const int MOD = 1e9 + 7;
        int f[target + 1];
        memset(f, 0, sizeof f);
        f[0] = 1;
        for (auto &t: types) {
            int c = t[0], m = t[1];
            for (int i = target; i >= m; i--) {
                for (int j = 1; j <= c && j * m <= i; j++) {
                    f[i] = (f[i] + f[i - j * m]) % MOD;
                }
            }
        }
        return f[target];
    }
};