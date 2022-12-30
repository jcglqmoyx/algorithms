#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    vector<int> path;
    vector<vector<int>> res;

    void dfs(deque<TreeNode *> dq) {
        if (dq.empty()) {
            res.push_back(path);
            return;
        }
        int n = (int) dq.size();
        for (int i = 0; i < n; i++) {
            auto t = dq.front();
            dq.pop_front();
            path.push_back(t->val);
            if (t->left) dq.push_back(t->left);
            if (t->right) dq.push_back(t->right);
            dfs(dq);
            if (t->left) dq.pop_back();
            if (t->right) dq.pop_back();
            dq.push_back(t);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> BSTSequences(TreeNode *root) {
        if (!root) return {path};
        deque<TreeNode *> dq;
        dq.push_back(root);
        dfs(dq);
        return res;
    }
};