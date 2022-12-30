#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return res;
    }

private:
    vector<int> path;
    vector<vector<int>> res;

    void dfs(vector<int> &candidates, int target, int index) {
        if (target == 0) {
            res.emplace_back(path);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] <= target) {
                path.push_back(candidates[i]);
                dfs(candidates, target - candidates[i], i + 1);
                path.pop_back();
            } else break;
        }
    }
};