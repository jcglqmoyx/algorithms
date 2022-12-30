#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    vector<int> v;

    void dfs(TreeNode *root) {
        if (!root) return;
        v.push_back(root->val);
        dfs(root->left), dfs(root->right);
    }

public:
    vector<vector<int>> closestNodes(TreeNode *root, vector<int> &queries) {
        int n = (int) queries.size(), INF = 1e9;
        dfs(root);
        v.push_back(-INF);
        v.push_back(INF);
        sort(v.begin(), v.end());
        vector<vector<int>> res(n);
        for (int i = 0; i < n; i++) {
            int a = -1, b = -1;
            int num = *lower_bound(v.begin(), v.end(), queries[i]);
            if (num != INF) b = num;
            auto it = upper_bound(v.begin(), v.end(), queries[i]);
            it--;
            num = *it;
            if (num != -INF) a = num;
            res[i] = {a, b};
        }
        return res;
    }
};