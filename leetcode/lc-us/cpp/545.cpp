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
    vector<int> left, leaves;
    stack<int> right;

    void dfs_left(TreeNode *root) {
        if (!root) return;
        if (!root->left && !root->right) return;
        left.push_back(root->val);
        if (root->left) dfs_left(root->left);
        else dfs_left(root->right);
    }

    void dfs_leaves(TreeNode *root) {
        if (!root) return;
        if (!root->left && !root->right) leaves.push_back(root->val);
        dfs_leaves(root->left);
        dfs_leaves(root->right);
    }

    void dfs_right(TreeNode *root) {
        if (!root) return;
        if (!root->left && !root->right) return;
        right.push(root->val);
        if (root->right) dfs_right(root->right);
        else dfs_right(root->left);
    }

public:
    vector<int> boundaryOfBinaryTree(TreeNode *root) {
        vector<int> res = {root->val};
        if (!root->left && !root->right) return res;
        dfs_left(root->left);
        dfs_leaves(root);
        dfs_right(root->right);
        for (int x: left) res.push_back(x);
        for (int x: leaves) res.push_back(x);
        while (!right.empty()) {
            int t = right.top();
            right.pop();
            res.push_back(t);
        }
        return res;
    }
};