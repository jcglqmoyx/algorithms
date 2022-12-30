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
    vector<int> lonely_nodes;

    void dfs(TreeNode *node) {
        if (!node) return;
        if (!node->left && node->right) lonely_nodes.push_back(node->right->val);
        if (node->left && !node->right) lonely_nodes.push_back(node->left->val);
        dfs(node->left);
        dfs(node->right);
    }

public:
    vector<int> getLonelyNodes(TreeNode *root) {
        dfs(root);
        return lonely_nodes;
    }
};