#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int n, res;

    void dfs(TreeNode *root) {
        if (!root) return;
        dfs(root->right);
        n--;
        if (n == 0) {
            res = root->val;
            return;
        }
        dfs(root->left);
    }

public:
    int kthLargest(TreeNode *root, int k) {
        n = k;
        dfs(root);
        return res;
    }
};