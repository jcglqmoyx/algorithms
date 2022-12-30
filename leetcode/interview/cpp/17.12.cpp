#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode *dummy = new TreeNode(0), *cur = dummy;

    void inorder(TreeNode *node) {
        if (!node) return;
        inorder(node->left);
        node->left = nullptr;
        cur->right = node;
        cur = cur->right;
        inorder(node->right);
    }

public:
    TreeNode *convertBiNode(TreeNode *root) {
        inorder(root);
        return dummy->right;
    }
};