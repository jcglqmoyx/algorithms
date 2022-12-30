#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode *ans;

    bool dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root) return false;
        bool l_son = dfs(root->left, p, q);
        bool r_son = dfs(root->right, p, q);
        if (l_son && r_son || (root == p || root == q) && (l_son || r_son)) {
            ans = root;
        }
        return l_son || r_son || root == p || root == q;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        dfs(root, p, q);
        return ans;
    }
};