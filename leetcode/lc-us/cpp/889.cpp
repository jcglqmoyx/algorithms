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
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder) {
        pre = preorder, post = postorder;
        int n = (int) preorder.size();
        for (int i = 0; i < n; i++) pos[postorder[i]] = i;
        return build(0, n - 1, 0, n - 1);
    }

private:
    vector<int> pre, post;
    unordered_map<int, int> pos;

    TreeNode *build(int prev_low, int prev_high, int post_low, int post_high) {
        if (prev_low > prev_high) return nullptr;
        auto root = new TreeNode(pre[prev_low]);
        if (prev_low == prev_high) return root;
        int idx = pos[pre[prev_low + 1]];
        root->left = build(prev_low + 1, prev_low + idx - post_low + 1, post_low, idx);
        root->right = build(prev_low + idx - post_low + 2, prev_high, idx + 1, post_high - 1);
        return root;
    }
};