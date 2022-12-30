#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumScore(vector<int> &nums, vector<int> &multipliers) {
        int n = (int) nums.size(), m = (int) multipliers.size();
        if (n > m << 1) {
            for (int i = m, j = n - m; j < n; j++) {
                nums[i++] = nums[j];
            }
            n = m << 1;
        }
        vector<vector<int>> f(n + 2, vector<int>(n + 1));
        for (int len = n - m + 1; len <= n; len++) {
            for (int i = 1; i + len - 1 <= n; i++) {
                int j = i + len - 1;
                int x = multipliers[n - len];
                f[i][j] = max(f[i + 1][j] + nums[i - 1] * x, f[i][j - 1] + nums[j - 1] * x);
            }
        }
        return f[1][n];
    }
};