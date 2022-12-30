#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> subset;
    vector<vector<int>> res;

    void backtrack(int cur, vector<int> &nums) {
        if (cur == nums.size()) {
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[cur]);
        backtrack(cur + 1, nums);
        subset.pop_back();
        backtrack(cur + 1, nums);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums) {
        backtrack(0, nums);
        return res;
    }
};