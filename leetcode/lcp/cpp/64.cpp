#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    tuple<int, int, int, int> dfs(TreeNode *root) {
        if (root == nullptr) return {0, 0, 0, 0};
        auto[la, lb, lc, ld] = dfs(root->left);
        auto[ra, rb, rc, rd] = dfs(root->right);
        int v = root->val;
        int x = min({la + ra + (v ? 1 : 0), lb + rb + (v ? 1 : 2), lc + rc + (v ? 1 : 2), ld + rd + (v ? 3 : 2)});
        int y = min({la + ra + (v ? 0 : 1), lb + rb + (v ? 2 : 1), lc + rc + (v ? 2 : 1), ld + rd + (v ? 2 : 3)});
        int z = min({la + ra + (v ? 2 : 1), lb + rb + (v ? 2 : 3), lc + rc + (v ? 0 : 1), ld + rd + (v ? 2 : 1)});
        int k = min({la + ra + (v ? 1 : 2), lb + rb + (v ? 3 : 2), lc + rc + (v ? 1 : 0), ld + rd + (v ? 1 : 2)});
        return {x, y, z, k};
    }

public:
    int closeLampInTree(TreeNode *root) {
        auto[x, y, z, k] = dfs(root);
        return min({x, y + 1, z + 1, k + 2});
    }
};