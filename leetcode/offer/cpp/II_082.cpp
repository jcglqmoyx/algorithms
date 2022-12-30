#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        t = target, nums = candidates, st.resize(nums.size());
        sort(nums.begin(), nums.end());
        dfs(0, 0);
        return paths;
    }

private:
    int t;
    vector<int> nums, path;
    vector<bool> st;
    vector<vector<int>> paths;

    void dfs(int index, int sum) {
        if (sum == t) {
            paths.push_back(path);
            return;
        }
        if (index == nums.size() || sum > t) return;
        for (int i = index; i < nums.size(); i++) {
            if (st[i] || i > index && nums[i] == nums[i - 1] && !st[i - 1]) continue;
            path.push_back(nums[i]);
            st[i] = true;
            dfs(i + 1, sum + nums[i]);
            path.pop_back();
            st[i] = false;
        }
    }
};