#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        dfs(nums, 0);
        return paths;
    }

private:
    vector<int> path;
    vector<vector<int>> paths;

    void dfs(vector<int> &nums, int index) {
        if (index == nums.size()) {
            paths.push_back(path);
            return;
        }
        path.push_back(nums[index]);
        dfs(nums, index + 1);
        path.pop_back();
        dfs(nums, index + 1);
    }
};