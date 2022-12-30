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
    int res;

    // max, min, sum, is_BST
    tuple<int, int, int, bool> dfs(TreeNode *node) {
        if (!node->left && !node->right) {
            res = max(res, node->val);
            return {node->val, node->val, node->val, true};
        }
        int sum = node->val;
        tuple<int, int, int, bool> l, r;
        if (node->left) l = dfs(node->left);
        if (node->right) r = dfs(node->right);
        if (node->left && (!get<3>(l) || get<0>(l) >= node->val)) return {0, 0, 0, false};
        if (node->right && (!get<3>(r) || get<1>(r) <= node->val)) return {0, 0, 0, false};
        int mx = node->val, mn = node->val;
        if (node->left) mn = get<1>(l), sum += get<2>(l);
        if (node->right) mx = get<0>(r), sum += get<2>(r);
        res = max(res, sum);
        return {mx, mn, sum, true};
    }

public:
    int maxSumBST(TreeNode *root) {
        res = 0;
        dfs(root);
        return res;
    }
};