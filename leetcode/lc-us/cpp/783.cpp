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
    int min_diff = INT32_MAX;
    TreeNode *prev = nullptr;

    void inorder(TreeNode *root) {
        if (!root) {
            return;
        }
        inorder(root->left);
        if (prev != nullptr) {
            min_diff = min(min_diff, root->val - prev->val);
            if (min_diff == 1) {
                return;
            }
        }
        prev = root;
        inorder(root->right);
    }

public:
    int minDiffInBST(TreeNode *root) {
        inorder(root);
        return min_diff;
    }
};