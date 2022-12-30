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
    unordered_set<int> st;
    vector<TreeNode *> ans;

    TreeNode *post(TreeNode *t) {
        if (!t) return nullptr;
        TreeNode *tl = post(t->left), *tr = post(t->right);
        t->left = tl, t->right = tr;
        if (st.count(t->val)) {
            if (tl) ans.emplace_back(tl);
            if (tr) ans.emplace_back(tr);
            return nullptr;
        }
        return t;
    }

public:
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
        for (auto &x: to_delete) st.insert(x);
        if (!st.count(root->val)) ans.emplace_back(root);
        post(root);
        return ans;
    }
};