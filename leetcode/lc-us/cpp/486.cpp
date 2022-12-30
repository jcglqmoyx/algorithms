#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int> &nums) {
        int n = (int) nums.size();
        vector<vector<int>> f(n, vector<int>(n));
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (i == j) f[i][j] = nums[i];
                else f[i][j] = max(nums[i] - f[i + 1][j], nums[j] - f[i][j - 1]);
            }
        }
        return f[0][n - 1] >= 0;
    }
};