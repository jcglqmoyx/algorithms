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
    using LL = long long;
    const int MOD = 1e9 + 7;
    LL sum = 0;
    LL res = 0;

    void dfs1(TreeNode *root) {
        if (!root) return;
        sum += root->val;
        dfs1(root->left);
        dfs1(root->right);
    }

    LL dfs2(TreeNode *root) {
        if (!root) return 0;
        LL l = dfs2(root->left), r = dfs2(root->right);
        res = max(res, (sum - l) * l);
        res = max(res, (sum - r) * r);
        return l + r + root->val;
    }

public:
    int maxProduct(TreeNode *root) {
        dfs1(root);
        dfs2(root);
        return (int) (res % MOD);
    }
};