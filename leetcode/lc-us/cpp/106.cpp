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

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n = (int) inorder.size();
        for (int i = 0; i < n; i++) map[inorder[i]] = i;
        return build(inorder, postorder, 0, n - 1, 0, n - 1);
    }

    TreeNode *build(const vector<int> &inorder, const vector<int> &postorder, int inorder_left, int inorder_right,
                    int postorder_left, int postorder_right) {
        if (postorder_left > postorder_right) return nullptr;
        int inorder_root = map[postorder[postorder_right]];
        int size_left_subtree = inorder_root - inorder_left;
        auto *root = new TreeNode(inorder[inorder_root]);
        root->left = build(inorder, postorder, inorder_left, inorder_root - 1, postorder_left,
                           postorder_left + size_left_subtree - 1);
        root->right = build(inorder, postorder, inorder_root + 1, inorder_right, postorder_left + size_left_subtree,
                            postorder_right - 1);
        return root;
    }
};