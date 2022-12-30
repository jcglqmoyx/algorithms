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
    unordered_map<int, int> map;

    TreeNode *build(const vector<int> &preorder, const vector<int> &inorder, int preorder_left, int preorder_right,
                    int inorder_left, int inorder_right) {
        if (preorder_left > preorder_right) return nullptr;
        auto *root = new TreeNode(preorder[preorder_left]);
        int inorder_root = map[preorder[preorder_left]];
        int size_left_subtree = inorder_root - inorder_left;
        root->left = build(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left,
                           inorder_root - 1);
        root->right = build(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1,
                            inorder_right);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) map[inorder[i]] = i;
        return build(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};