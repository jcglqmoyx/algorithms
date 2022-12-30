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
    int ans = 1;

    int longestConsecutive(TreeNode *root) {
        if (!root) return 0;
        dfs(root, 1);
        return ans;
    }

    void dfs(TreeNode *node, int len) {
        if (!node) {
            return;
        }
        ans = max(ans, len);
        if (node->left && node->left->val == node->val + 1) {
            dfs(node->left, len + 1);
        } else {
            dfs(node->left, 1);
        }
        if (node->right && node->right->val == node->val + 1) {
            dfs(node->right, len + 1);
        } else {
            dfs(node->right, 1);
        }
    }
};