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
    int longestConsecutive(TreeNode *root) {
        int res = 0;
        dfs(root, res);
        return res;
    }

private:
    pair<int, int> dfs(TreeNode *root, int &res) {
        if (!root) return {0, 0};
        auto p = dfs(root->left, res), q = dfs(root->right, res);
        int inc = 1, dec = 1;
        if (root->left) {
            if (root->val == root->left->val + 1) {
                inc = max(inc, p.first + 1);
            } else if (root->val == root->left->val - 1) {
                dec = max(dec, p.second + 1);
            }
        }
        if (root->right) {
            if (root->val == root->right->val + 1) {
                inc = max(inc, q.first + 1);
            } else if (root->val == root->right->val - 1) {
                dec = max(dec, q.second + 1);
            }
        }
        res = max(res, inc + dec - 1);
        return {inc, dec};
    }
};