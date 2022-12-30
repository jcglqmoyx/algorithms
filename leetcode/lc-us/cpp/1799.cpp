#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxScore(vector<int> &nums) {
        int n = (int) nums.size();
        vector<int> f(1 << n);
        vector<vector<int>> gcd(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                gcd[i][j] = __gcd(nums[i], nums[j]);
            }
        }
        for (int i = 0; i < 1 << n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) cnt++;
            }
            if (!(cnt & 1)) {
                for (int j = 0; j < n; j++) {
                    if (i >> j & 1) {
                        for (int k = j + 1; k < n; k++) {
                            if (i >> k & 1) {
                                f[i] = max(f[i], f[i - (1 << j) - (1 << k)] + ((n - cnt) / 2 + 1) * gcd[j][k]);
                            }
                        }
                    }
                }
            }
        }
        return f[(1 << n) - 1];
    }
};