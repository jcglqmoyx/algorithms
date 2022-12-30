#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> path;
    vector<vector<int>> res;


    void backtrack(int cur, int n, int k) {
        if (path.size() + n - cur + 1 < k) return;
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        path.push_back(cur);
        backtrack(cur + 1, n, k);
        path.pop_back();
        backtrack(cur + 1, n, k);
    }

public:
    vector<vector<int>> combine(int n, int k) {
        backtrack(1, n, k);
        return res;
    }
};