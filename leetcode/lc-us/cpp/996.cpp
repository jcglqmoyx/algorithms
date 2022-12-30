#include <bits/stdc++.h>

using namespace std;

class Solution {
    int fact[13] = {1};

    void init() {
        for (int i = 1; i <= 12; i++) fact[i] = fact[i - 1] * i;
    }

    bool is_square(int n) {
        int x = sqrt(n);
        return x * x == n;
    }

public:
    int numSquarefulPerms(vector<int> &nums) {
        init();
        int n = (int) nums.size(), res = 0;
        vector<vector<int>> f(1 << n, vector<int>(n));
        for (int i = 0; i < n; i++) f[1 << i][i] = 1;
        for (int i = 0; i < 1 << n; i++) {
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) {
                    for (int k = 0; k < n; k++) {
                        if (!((i >> k) & 1) && is_square(nums[j] + nums[k])) {
                            f[i | 1 << k][k] += f[i][j];
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) res += f[(1 << n) - 1][i];
        unordered_map<int, int> hash;
        for (int x: nums) hash[x]++;
        for (auto[k, v]: hash) res /= fact[v];
        return res;
    }
};