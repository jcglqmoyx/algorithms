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
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        dfs(root, 1);
        return min_depth;
    }

private:
    int min_depth = 100000;

    void dfs(TreeNode *root, int depth) {
        if (!root) return;
        if (is_leaf(root)) min_depth = min(min_depth, depth);
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }

    bool is_leaf(TreeNode *node) {
        return !node->left && !node->right;
    }
};