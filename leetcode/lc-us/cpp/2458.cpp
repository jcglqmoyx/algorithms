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

const int N = 1e5 + 10;

int mx;
int h[N];

class Solution {
    void dfs1(TreeNode *node, int depth) {
        h[node->val] = mx;
        mx = max(mx, depth);
        if (node->left) dfs1(node->left, depth + 1);
        if (node->right) dfs1(node->right, depth + 1);
    }

    void dfs2(TreeNode *node, int depth) {
        h[node->val] = max(h[node->val], mx);
        mx = max(mx, depth);
        if (node->right) dfs2(node->right, depth + 1);
        if (node->left) dfs2(node->left, depth + 1);
    }

public:
    vector<int> treeQueries(TreeNode *root, vector<int> &queries) {
        memset(h, 0, sizeof h);

        mx = 0, dfs1(root, 0);
        mx = 0, dfs2(root, 0);

        int n = (int) queries.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = h[queries[i]];
        }
        return res;
    }
};