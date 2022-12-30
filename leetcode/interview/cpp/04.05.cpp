#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    vector<int> nums;

    void inorder(TreeNode *root) {
        if (!root) return;
        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
    }

public:
    bool isValidBST(TreeNode *root) {
        if (!root) return true;
        inorder(root);
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] >= nums[i + 1]) return false;
        }
        return true;
    }
};