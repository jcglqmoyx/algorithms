#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<bool> st;
    vector<int> path;
    vector<vector<int>> res;

    void backtrack(vector<int> &nums, int idx) {
        if (idx == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (st[i] || i > 0 && nums[i] == nums[i - 1] && !st[i - 1]) continue;
            path.push_back(nums[i]);
            st[i] = true;
            backtrack(nums, idx + 1);
            path.pop_back();
            st[i] = false;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        st.resize(nums.size());
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return res;
    }
};