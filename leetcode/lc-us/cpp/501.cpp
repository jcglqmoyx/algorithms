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
    long long prev = INT64_MIN;
    int freq = 1, max_freq = 1;
    vector<int> modes;

    void inorder(TreeNode *root) {
        if (!root) return;
        inorder(root->left);
        if (root->val == prev) {
            freq++;
            max_freq = max(max_freq, freq);
        } else {
            max_freq = max(max_freq, freq);
            freq = 1;
        }
        prev = root->val;
        inorder(root->right);
    }

    void dfs(TreeNode *root) {
        if (!root) return;
        dfs(root->left);
        if (root->val == prev) {
            freq++;
            if (freq == max_freq) modes.push_back(root->val);
        } else {
            freq = 1;
            if (freq == max_freq) modes.push_back(root->val);
        }
        prev = root->val;
        dfs(root->right);
    }

public:
    vector<int> findMode(TreeNode *root) {
        inorder(root);
        freq = 1;
        prev = INT64_MIN;
        dfs(root);
        return modes;
    }
};