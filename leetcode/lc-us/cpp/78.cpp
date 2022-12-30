#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> path;
    vector<vector<int>> res;

    void dfs(int cur, vector<int> nums) {
        if (cur == nums.size()) {
            res.push_back(path);
            return;
        }
        path.push_back(nums[cur]);
        dfs(cur + 1, nums);
        path.pop_back();
        dfs(cur + 1, nums);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums) {
        dfs(0, nums);
        return res;
    }
};