#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        path.resize(nums.size()), st.resize(nums.size());
        dfs(nums, 0);
        return paths;
    }

private:
    vector<bool> st;
    vector<int> path;
    vector<vector<int>> paths;

    void dfs(vector<int> &nums, int index) {
        if (index == nums.size()) {
            paths.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!st[i]) {
                st[i] = true;
                path[index] = nums[i];
                dfs(nums, index + 1);
                st[i] = false;
            }
        }
    }
};