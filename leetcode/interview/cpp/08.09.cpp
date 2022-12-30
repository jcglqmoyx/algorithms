#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<string> res;

    void dfs(int n, int left, int right, string cur) {
        if (left > n || right > n || right > left) return;
        if (left == n && right == n) {
            res.push_back(cur);
            return;
        }
        dfs(n, left + 1, right, cur + "(");
        dfs(n, left, right + 1, cur + ")");
    }

public:
    vector<string> generateParenthesis(int n) {
        string cur;
        dfs(n, 0, 0, cur);
        return res;
    }
};