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
    int maxPathSum(TreeNode *root) {
        dfs(root);
        return res;
    }

private:
    int res = -1e9l;

    int dfs(TreeNode *node) {
        if (!node) return 0;
        int l = max(0, dfs(node->left)), r = max(0, dfs(node->right));
        res = max(res, node->val + l + r);
        return node->val + max(l, r);
    }
};