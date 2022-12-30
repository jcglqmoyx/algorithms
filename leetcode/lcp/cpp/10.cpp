#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    pair<int, double> dfs(TreeNode *node) {
        if (!node) return {0, 0};
        auto l = dfs(node->left), r = dfs(node->right);
        return {node->val + l.first + r.first, node->val + max(max(l.second, r.second), (l.first + r.first) / 2.0)};
    }

public:
    double minimalExecTime(TreeNode *root) {
        return dfs(root).second;
    }
};

