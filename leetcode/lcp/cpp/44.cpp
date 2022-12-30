#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    unordered_set<int> s;

    void dfs(TreeNode *node) {
        if (!node) return;
        s.insert(node->val);
        dfs(node->left);
        dfs(node->right);
    }

public:
    int numColor(TreeNode *root) {
        dfs(root);
        return (int) s.size();
    }
};