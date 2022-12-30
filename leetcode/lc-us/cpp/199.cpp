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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode *> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            res.push_back(nodes.back()->val);
            for (int i = (int) nodes.size(); i > 0; i--) {
                TreeNode *node = nodes.front();
                nodes.pop();
                if (node->left) nodes.push(node->left);
                if (node->right) nodes.push(node->right);
            }
        }
        return res;
    }
};