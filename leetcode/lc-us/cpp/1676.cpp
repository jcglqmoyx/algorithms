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
    unordered_set<TreeNode *> set;

    TreeNode *dfs(TreeNode *root) {
        if (!root) return nullptr;
        if (set.count(root)) return root;
        auto l = dfs(root->left), r = dfs(root->right);
        if (l && r) return root;
        else if (l) return l;
        else return r;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, vector<TreeNode *> &nodes) {
        for (auto node: nodes) set.insert(node);
        return dfs(root);
    }
};