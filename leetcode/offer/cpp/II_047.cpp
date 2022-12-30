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
public:
    TreeNode *pruneTree(TreeNode *root) {
        init(root);
        if (root->val == 0) return nullptr;
        auto res = prune(root);
        restore(root);
        return root;
    }

private:
    unordered_map<TreeNode *, int> hash;

    int init(TreeNode *node) {
        if (!node) return 0;
        int l = init(node->left), r = init(node->right);
        hash[node] = node->val;
        node->val = l + r + node->val;
        return node->val;
    }

    TreeNode *prune(TreeNode *node) {
        if (!node || !node->val) return nullptr;
        if (node->left && node->left->val == 0) node->left = nullptr;
        if (node->right && node->right->val == 0) node->right = nullptr;
        prune(node->left);
        prune(node->right);
        return node;
    }

    void restore(TreeNode *root) {
        if (!root) return;
        restore(root->left);
        restore(root->right);
        root->val = hash[root];
    }
};