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
    int max_depth = 0;

    void dfs(TreeNode *root, int depth) {
        if (!root) {
            return;
        }
        max_depth = max(max_depth, depth);
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }

public:
    int maxDepth(TreeNode *root) {
        dfs(root, 1);
        return max_depth;
    }
};