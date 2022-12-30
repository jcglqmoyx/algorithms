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
    bool isBalanced(TreeNode *root) {
        return dfs(root) >= 0;
    }

    int dfs(TreeNode *node) {
        if (!node) return 0;
        int l, r;
        if ((l = dfs(node->left)) == -1 || (r = dfs(node->right)) == -1 || abs(l - r) > 1) return -1;
        return max(l, r) + 1;
    }
};