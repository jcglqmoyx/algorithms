#include <bits/stdc++.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *mirrorTree(TreeNode *root) {
        if (!root) return nullptr;
        root->left = mirrorTree(root->left);
        root->right = mirrorTree(root->right);
        auto tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        return root;
    }
};