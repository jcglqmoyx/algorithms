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
    int res = 0;
    const int INVALID = -1;
    struct Node {
        int l, r, sz;
    };

    Node dfs(TreeNode *root) {
        if (!root->left && !root->right) {
            res = max(res, 1);
            return {root->val, root->val, 1};
        }
        bool valid = true;
        int l = root->val, r = root->val, sz = 1;
        if (root->left) {
            Node L = dfs(root->left);
            if (L.sz != INVALID && L.r < root->val) {
                l = L.l;
                sz += L.sz;
            } else {
                valid = false;
            }
        }
        if (root->right) {
            Node R = dfs(root->right);
            if (R.sz != INVALID && R.l > root->val) {
                r = R.r;
                sz += R.sz;
            } else {
                valid = false;
            }
        }
        if (valid) {
            res = max(res, sz);
            return {l, r, sz};
        } else {
            return {-1, -1, INVALID};
        }
    }

public:
    int largestBSTSubtree(TreeNode *root) {
        if (!root) return res;
        dfs(root);
        return res;
    }
};