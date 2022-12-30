#include <bits/stdc++.h>

using namespace std;

class Solution {
    const double eps = 1e-8;

    vector<double> get(vector<double> &nums, int i, int j, double x) {
        vector<double> res;
        for (int k = 0; k < (int) nums.size(); k++) {
            if (k != i && k != j) {
                res.push_back(nums[k]);
            }
        }
        res.push_back(x);
        return res;
    }

    bool dfs(vector<double> nums) {
        int n = (int) nums.size();
        if (n == 1) return fabs(nums[0] - 24) < eps;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    if (dfs(get(nums, i, j, nums[i] + nums[j]))) return true;
                    if (dfs(get(nums, i, j, nums[i] - nums[j]))) return true;
                    if (dfs(get(nums, i, j, nums[i] * nums[j]))) return true;
                    if (dfs(get(nums, i, j, nums[i] / nums[j]))) return true;
                }
            }
        }
        return false;
    }

public:
    bool judgePoint24(vector<int> &cards) {
        vector<double> nums(cards.begin(), cards.end());
        return dfs(nums);
    }
};