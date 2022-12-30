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
    const int INF = 1e7;
    struct Status {
        int a, b, c;
    };

    Status dfs(TreeNode *node) {
        if (!node) return {INF, 0, 0};
        auto l = dfs(node->left), r = dfs(node->right);
        int a = l.c + r.c + 1, b = min(a, min(l.a + r.b, r.a + l.b)), c = min(a, l.b + r.b);
        return {a, b, c};
    }

public:
    int minCameraCover(TreeNode *root) {
        auto t = dfs(root);
        return min(t.a, t.b);
    }
};