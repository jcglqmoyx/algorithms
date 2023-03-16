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
    unordered_map<int, int> pos;
    vector<int> post;
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n = (int) inorder.size();
        for (int i = 0; i < n; i++) pos[inorder[i]] = i;
        post = std::move(postorder);
        return construct(0, n - 1, 0, n - 1);
    }

    TreeNode *construct(int il, int ir, int pl, int pr) {
        if (pl > pr) return nullptr;
        auto root = new TreeNode(post[pr]);
        int idx = pos[post[pr]];
        root->left = construct(il, idx - 1, pl, pl + idx - il - 1);
        root->right = construct(idx + 1, ir, pl + idx - il, pr - 1);
        return root;
    }
};