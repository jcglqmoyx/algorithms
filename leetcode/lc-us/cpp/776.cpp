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
    vector<TreeNode *> splitBST(TreeNode *root, int target) {
        if (!root) return {nullptr, nullptr};
        if (root->val <= target) {
            auto r = splitBST(root->right, target);
            root->right = r[0];
            return {root, r[1]};
        } else {
            auto l = splitBST(root->left, target);
            root->left = l[1];
            return {l[0], root};
        }
    }
};