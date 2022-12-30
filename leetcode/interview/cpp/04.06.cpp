#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode *min_node(TreeNode *node) {
        auto p = node;
        while (p && p->left) {
            p = p->left;
        }
        return p;
    }

public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        if (p->right) return min_node(p->right);
        TreeNode *successor = nullptr;
        while (root != p) {
            if (root->val > p->val) {
                successor = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        if (!successor) return min_node(p->right);
        return successor;
    }
};