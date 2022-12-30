#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    bool flag = false;
    TreeNode *successor = nullptr;

    void inorder(TreeNode *node, TreeNode *p) {
        if (!node) return;
        inorder(node->left, p);
        if (flag) {
            successor = node;
            flag = false;
            return;
        }
        if (p == node) {
            flag = true;
        }
        inorder(node->right, p);
    }

public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        inorder(root, p);
        return successor;
    }
};