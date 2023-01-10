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
    /*
     * param node: the root of the tree
     * return: the lowest common ancestor of the deepest leaves of node, the depth of node
     */
    pair<TreeNode *, int> dfs(TreeNode *node) {
        if (!node) return {nullptr, 0};
        auto l = dfs(node->left), r = dfs(node->right);
        if (l.second == r.second) return {node, l.second + 1};
        else if (l.second > r.second) return {l.first, l.second + 1};
        else return {r.first, r.second + 1};
    }

public:
    TreeNode *lcaDeepestLeaves(TreeNode *root) {
        return dfs(root).first;
    }
};