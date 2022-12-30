#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int paths = 0;

    void preorder(TreeNode *node, int sum) {
        if (!node) return;
        dfs(node, sum);
        preorder(node->left, sum);
        preorder(node->right, sum);
    }

    void dfs(TreeNode *root, int sum) {
        if (!root) {
            return;
        }
        if (root->val == sum) {
            paths++;
        }
        dfs(root->left, sum - root->val);
        dfs(root->right, sum - root->val);
    }

public:
    int pathSum(TreeNode *root, int sum) {
        preorder(root, sum);
        return paths;
    }
};