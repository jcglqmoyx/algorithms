#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> levelOrder(TreeNode *root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            for (auto it = q.size(); it; it--) {
                TreeNode *node = q.front();
                q.pop();
                res.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return res;
    }
};