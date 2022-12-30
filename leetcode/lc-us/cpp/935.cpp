#include <bits/stdc++.h>

using namespace std;

class Solution {
    const int MOD = 1e9 + 7;
public:
    int knightDialer(int n) {
        if (n == 1) return 10;
        vector<vector<int>> f = {
                {4, 6},
                {6, 8},
                {7, 9},
                {4, 8},
                {0, 3, 9},
                {},
                {0, 1, 7},
                {2, 6},
                {1, 3},
                {2, 4}
        };
        int cnt[10] = {};
        for (int i = 0; i <= 9; i++) cnt[i] = 1;
        for (int iter = 0; iter < n - 1; iter++) {
            int tmp[10] = {};
            for (int i = 0; i <= 9; i++) {
                for (int x: f[i]) {
                    tmp[x] = (tmp[x] + cnt[i]) % MOD;
                }
            }
            for (int i = 0; i <= 9; i++) cnt[i] = tmp[i];
        }
        int res = 0;
        for (int i = 0; i <= 9; i++) res = (res + cnt[i]) % MOD;
        return res;
    }
};