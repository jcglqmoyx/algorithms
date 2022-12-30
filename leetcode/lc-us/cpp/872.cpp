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
    vector<int> nums1, nums2;

    void dfs(TreeNode *root, vector<int> &nums) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            nums.push_back(root->val);
        }
        dfs(root->left, nums);
        dfs(root->right, nums);
    }

public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        dfs(root1, nums1);
        dfs(root2, nums2);
        if (nums1.size() != nums2.size()) {
            return false;
        }
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] != nums2[i]) {
                return false;
            }
        }
        return true;
    }
};