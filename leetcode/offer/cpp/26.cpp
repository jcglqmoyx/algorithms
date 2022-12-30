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

    void preorder(TreeNode *root, TreeNode *node) {
        if (!root) return;
        if (root->val == node->val) {
            if (is_similar(root, node)) {
                flag = true;
                return;
            }
        }
        preorder(root->left, node);
        preorder(root->right, node);
    }

    bool is_similar(TreeNode *node1, TreeNode *node2) {
        if (!node2) return true;
        if (!node1) return false;
        if (node1->val != node2->val) return false;
        return is_similar(node1->left, node2->left) && is_similar(node1->right, node2->right);
    }

public:
    bool isSubStructure(TreeNode *A, TreeNode *B) {
        if (!B) return false;
        preorder(A, B);
        return flag;
    }
};