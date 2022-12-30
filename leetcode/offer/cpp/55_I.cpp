#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int max_depth = 0;

    void dfs(TreeNode *root, int depth) {
        if (!root) return;
        if (depth > max_depth) max_depth = depth;
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }

public:
    int maxDepth(TreeNode *root) {
        dfs(root, 1);
        return max_depth;
    }
};