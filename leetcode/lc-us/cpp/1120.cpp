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
    double maximumAverageSubtree(TreeNode *root) {
        dfs(root);
        return res;
    }

private:
    double res = 0;

    pair<double, int> dfs(TreeNode *node) {
        if (!node) return {0, 0};
        auto l = dfs(node->left);
        auto r = dfs(node->right);
        double x = l.first + r.first + node->val;
        int y = l.second + r.second + 1;
        res = max(res, x / y);
        return {x, y};
    }
};