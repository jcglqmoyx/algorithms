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
    TreeNode *expandBinaryTree(TreeNode *root) {
        dfs(root);
        return root;
    }

private:
    void dfs(TreeNode *root) {
        if (!root) return;
        if (root->left) {
            auto left = root->left;
            auto node = new TreeNode(-1, left, nullptr);
            root->left = node;
            dfs(left);
        }
        if (root->right) {
            auto right = root->right;
            auto node = new TreeNode(-1, nullptr, right);
            root->right = node;
            dfs(right);
        }
    }
};