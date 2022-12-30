#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> path;
    vector<vector<int>> res;

    void backtrack(int cur) {
        if (cur == path.size()) res.push_back(path);
        for (int i = cur; i < path.size(); i++) {
            swap(path[i], path[cur]);
            backtrack(cur + 1);
            swap(path[i], path[cur]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums) {
        path = nums;
        backtrack(0);
        return res;
    }
};