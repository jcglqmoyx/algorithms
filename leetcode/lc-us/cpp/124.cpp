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
    int max_sum = -1e9;

    int dfs(TreeNode *root) {
        if (!root) return 0;
        int l = max(dfs(root->left), 0), r = max(dfs(root->right), 0);
        max_sum = max(max_sum, root->val + l + r);
        return root->val + max(l, r);
    }

public:
    int maxPathSum(TreeNode *root) {
        dfs(root);
        return max_sum;
    }
};