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

    pair<int, int> dfs(TreeNode *root) {
        if (!root) return {0, 0};
        auto l = dfs(root->left), r = dfs(root->right);
        int avg = (l.first + r.first + root->val) / (l.second + r.second + 1);
        if (avg == root->val) res++;
        return {l.first + r.first + root->val, l.second + r.second + 1};
    }

public:
    int averageOfSubtree(TreeNode *root) {
        dfs(root);
        return res;
    }
};