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
    int res = 0;

    void dfs(int mn, int mx, TreeNode *node) {
        if (!node) return;
        mn = min(mn, node->val);
        mx = max(mx, node->val);
        res = max(res, mx - mn);
        dfs(mn, mx, node->left);
        dfs(mn, mx, node->right);
    }

public:
    int maxAncestorDiff(TreeNode *root) {
        dfs(root->val, root->val, root);
        return res;
    }
};