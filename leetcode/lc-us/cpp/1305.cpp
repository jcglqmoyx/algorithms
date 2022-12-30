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
    void inorder(TreeNode *root, vector<int> &nums) {
        if (!root) {
            return;
        }
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }

public:
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
        vector<int> arr1, arr2;
        inorder(root1, arr1);
        inorder(root2, arr2);
        vector<int> nums;
        nums.reserve(arr1.size() + arr2.size());
        int i = 0, j = 0;
        while (i < arr1.size() || j < arr2.size()) {
            if (i < arr1.size() && j < arr2.size()) {
                if (arr1[i] < arr2[j]) nums.push_back(arr1[i++]);
                else nums.push_back(arr2[j++]);
            } else if (i < arr1.size()) nums.push_back(arr1[i++]);
            else nums.push_back(arr2[j++]);
        }
        return nums;
    }
};