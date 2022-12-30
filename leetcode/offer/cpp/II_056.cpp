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
    bool findTarget(TreeNode *root, int k) {
        dfs(root, k);
        return res;
    }

private:
    unordered_set<int> s;
    bool res = false;

    void dfs(TreeNode *node, int k) {
        if (!node) return;
        if (s.count(k - node->val)) {
            res = true;
            return;
        }
        s.insert(node->val);
        dfs(node->left, k);
        dfs(node->right, k);
    }
};