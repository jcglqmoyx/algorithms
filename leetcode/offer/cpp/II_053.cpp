#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        if (p->right) {
            auto node = p->right;
            while (node->left) node = node->left;
            return node;
        } else {
            TreeNode *node = nullptr;
            while (root != p) {
                if (root->val > p->val) node = root, root = root->left;
                else root = root->right;
                if (!root) return nullptr;
            }
            return node;
        }
    }
};