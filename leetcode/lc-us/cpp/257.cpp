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
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> paths;
        dfs(root, "", paths);
        return paths;
    }

    void dfs(TreeNode *root, string cur, vector<string> &paths) {
        if (!root) return;
        if (!cur.empty()) cur += "->" + to_string(root->val);
        else cur += to_string(root->val);
        if (!root->left && !root->right) paths.push_back(cur);
        dfs(root->left, cur, paths);
        dfs(root->right, cur, paths);
    }
};