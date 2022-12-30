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

    int dfs(TreeNode *root) {
        if (!root) return 0;
        int l = dfs(root->left), r = dfs(root->right);
        if (!root->left || root->val != root->left->val) l = 0;
        if (!root->right || root->val != root->right->val) r = 0;
        res = max(res, l + r);
        return max(l, r) + 1;
    }

public:
    int longestUnivaluePath(TreeNode *root) {
        dfs(root);
        return res;
    }
};