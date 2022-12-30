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
    vector<vector<int>> res;

    void dfs(TreeNode *node, vector<int> arr, int sum) {
        if (!node) return;
        if (is_leaf(node) && sum == node->val) {
            arr.push_back(node->val);
            res.push_back(arr);
            return;
        }
        arr.push_back(node->val);
        dfs(node->left, arr, sum - node->val);
        dfs(node->right, arr, sum - node->val);
    }

    bool is_leaf(TreeNode *node) {
        return !node->left && !node->right;
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        dfs(root, {}, sum);
        return res;
    }
};