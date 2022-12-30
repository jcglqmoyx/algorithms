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
    int distributeCoins(TreeNode *root) {
        res = 0;
        dfs(root);
        return res;
    }

private:
    int res;

    pair<int, int> dfs(TreeNode *node) {
        if (!node) return {0, 0};
        auto l = dfs(node->left), r = dfs(node->right);
        res += abs(l.first - l.second) + abs(r.first - r.second);
        return {l.first + r.first + node->val, l.second + r.second + 1};
    }
};