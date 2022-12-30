#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> path;
    vector<vector<int>> paths;
    vector<int> arr;

    void dfs(int cur, int prev) {
        if (cur == arr.size()) {
            if (path.size() >= 2) {
                paths.push_back(path);
            }
            return;
        }
        if (arr[cur] >= prev) {
            path.push_back(arr[cur]);
            dfs(cur + 1, arr[cur]);
            path.pop_back();
        }
        if (arr[cur] != prev) {
            dfs(cur + 1, prev);
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int> &nums) {
        arr = nums;
        dfs(0, INT32_MIN);
        return paths;
    }
};