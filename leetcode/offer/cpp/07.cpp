#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    unordered_map<int, int> map;

    TreeNode *construct(vector<int> &preorder, vector<int> &inorder, int preorder_left, int preorder_right,
                        int inorder_left, int inorder_right) {
        if (preorder_left > preorder_right) return nullptr;
        auto *root = new TreeNode(preorder[preorder_left]);
        int inorder_root = map[preorder[preorder_left]];
        int left_subtree_size = inorder_root - inorder_left;
        root->left = construct(preorder, inorder, preorder_left + 1, preorder_left + left_subtree_size, inorder_left,
                               inorder_root - 1);
        root->right = construct(preorder, inorder, preorder_left + left_subtree_size + 1, preorder_right,
                                inorder_root + 1, inorder_right);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }
        int n = preorder.size();
        return construct(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};