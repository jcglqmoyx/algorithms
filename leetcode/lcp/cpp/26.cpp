#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int res = 0, s = 1;

    int dfs(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int l = dfs(root->left), r = dfs(root->right);
        if (root->left && root->right) {
            res += !l && !r;
            s = !(l && r);
            return 1;
        }
        return l || r;
    }

public:
    int navigation(TreeNode *root) {
        int l = dfs(root->left), r = dfs(root->right);
        return res + ((l && r) ? 0 : s);
    }
};