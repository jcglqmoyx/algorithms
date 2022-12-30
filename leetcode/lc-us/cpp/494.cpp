#include <bits/stdc++.h>

using namespace std;

class Solution {
    int res = 0;

    void dfs(vector<int> &nums, int sum, int index, int target) {
        if (index == nums.size()) {
            if (sum == target) res++;
            return;
        }
        dfs(nums, sum + nums[index], index + 1, target);
        dfs(nums, sum - nums[index], index + 1, target);
    }

public:
    int findTargetSumWays(vector<int> &nums, int target) {
        dfs(nums, 0, 0, target);
        return res;
    }
};