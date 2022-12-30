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
    int n, m;
    vector<vector<string>> res;

    int get_height(TreeNode *root) {
        if (!root) return 0;
        int left = get_height(root->left) + 1;
        int right = get_height(root->right) + 1;
        return max(left, right);
    }

    void dfs(TreeNode *root, int r, int c) {
        if (!root) return;
        res[r][c] = to_string(root->val);
        dfs(root->left, r + 1, c - (int) pow(2, n - r - 2));
        dfs(root->right, r + 1, c + (int) pow(2, n - r - 2));
    }

public:
    vector<vector<string>> printTree(TreeNode *root) {
        n = get_height(root), m = (int) pow(2, n) - 1;
        res.resize(n, vector<string>(m));
        res[0][(m - 1) / 2] = to_string(root->val);
        dfs(root->left, 1, (m - 1) / 2 - (int) pow(2, n - 2));
        dfs(root->right, 1, (m - 1) / 2 + (int) pow(2, n - 2));
        return res;
    }
};