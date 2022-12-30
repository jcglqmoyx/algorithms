#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        t = target, nums = candidates;
        dfs(0, 0);
        return paths;
    }

private:
    int t;
    vector<int> nums, path;
    vector<vector<int>> paths;

    void dfs(int index, int sum) {
        if (sum == t) {
            paths.push_back(path);
            return;
        }
        if (index == nums.size() || sum > t) return;
        path.push_back(nums[index]);
        dfs(index, sum + nums[index]);
        path.pop_back();
        dfs(index + 1, sum);
    }
};