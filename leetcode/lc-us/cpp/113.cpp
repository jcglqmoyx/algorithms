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
    vector<int> path;
    vector<vector<int>> res;

    void dfs(TreeNode *root, int left) {
        if (!root) return;
        left -= root->val;
        path.push_back(root->val);
        if (!root->left && !root->right && !left) {
            res.push_back(path);
        }
        dfs(root->left, left);
        dfs(root->right, left);
        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        dfs(root, targetSum);
        return res;
    }
};