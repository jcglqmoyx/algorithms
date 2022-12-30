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
    int pseudoPalindromicPaths(TreeNode *root) {
        res = 0;
        int cnt = 0;
        dfs(root, cnt);
        return res;
    }

private:
    int res;

    void dfs(TreeNode *root, int cnt) {
        if (!root) return;

        cnt ^= 1 << root->val;

        if (!root->left && !root->right) {
            if (cnt == 0 || (cnt & (cnt - 1)) == 0) {
                res++;
            }
        }

        dfs(root->left, cnt);
        dfs(root->right, cnt);
    }
};