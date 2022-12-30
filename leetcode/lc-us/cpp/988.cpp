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
    vector<string> strings;

    void dfs(TreeNode *node, TreeNode *parent, string s) {
        if (!node) {
            if (!parent->left && !parent->right) strings.push_back(s);
            return;
        }
        s.push_back(node->val + 'a');
        dfs(node->left, node, s);
        dfs(node->right, node, s);
    }

public:
    string smallestFromLeaf(TreeNode *root) {
        dfs(root, nullptr, "");
        string res;
        for (auto &s: strings) {
            reverse(s.begin(), s.end());
            if (res.empty()) res = s;
            res = min(res, s);
        }
        return res;
    }
};