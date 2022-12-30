#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> path;
    vector<vector<int>> res;

    void backtrack(vector<int> &candidates, int target, int index) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        if (index == candidates.size() || target < 0) return;
        backtrack(candidates, target, index + 1);
        path.push_back(candidates[index]);
        backtrack(candidates, target - candidates[index], index);
        path.pop_back();
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        backtrack(candidates, target, 0);
        return res;
    }
};