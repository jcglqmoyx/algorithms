#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
        this->find_parents(root);
        dfs(target, nullptr, 0, k);
        return this->res;
    }

private:
    vector<int> res;
    unordered_map<int, TreeNode *> p;

    void find_parents(TreeNode *root) {
        if (!root) return;
        if (root->left) {
            p[root->left->val] = root;
            find_parents(root->left);
        }
        if (root->right) {
            p[root->right->val] = root;
            find_parents(root->right);
        }
    }

    void dfs(TreeNode *node, TreeNode *from, int depth, int k) {
        if (!node) return;
        if (depth == k) {
            res.push_back(node->val);
        }
        if (from != node->left) {
            dfs(node->left, node, depth + 1, k);
        }
        if (from != node->right) {
            dfs(node->right, node, depth + 1, k);
        }
        if (from != p[node->val]) {
            dfs(p[node->val], node, depth + 1, k);
        }
    }
};