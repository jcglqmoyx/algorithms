#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        int n = (int) nums.size();
        if (n == 1) return nums[0];
        else if (n == 2) return max(nums[0], nums[1]);
        vector<vector<int>> f(n, vector<int>(2));
        f[0][1] = nums[0], f[1][0] = nums[0], f[1][1] = nums[1];
        for (int i = 2; i < n; i++) {
            f[i][0] = max(f[i - 1][0], f[i - 1][1]);
            f[i][1] = max(max(f[i - 2][0], f[i - 2][1]) + nums[i], f[i][0]);
        }
        return max(f[n - 1][0], f[n - 1][1]);
    }
};