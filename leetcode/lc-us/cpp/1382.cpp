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
    vector<TreeNode *> nodes;

    void dfs(TreeNode *root) {
        if (!root) return;
        dfs(root->left);
        nodes.push_back(root);
        dfs(root->right);
    }

    TreeNode *construct(int low, int high) {
        if (low > high) return nullptr;
        int mid = (low + high) >> 1;
        auto *root = nodes[mid];
        root->left = construct(low, mid - 1);
        root->right = construct(mid + 1, high);
        return root;
    }

public:
    TreeNode *balanceBST(TreeNode *root) {
        dfs(root);
        return construct(0, (int) nodes.size() - 1);
    }
};