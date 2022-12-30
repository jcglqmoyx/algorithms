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
    bool is_leaf(TreeNode *node) {
        return !node->left && !node->right;
    }

public:
    int sumOfLeftLeaves(TreeNode *root) {
        if (!root || is_leaf(root)) {
            return 0;
        }
        int res = 0;
        queue<pair<TreeNode *, bool>> nodes;
        nodes.push({root, false});
        while (!nodes.empty()) {
            for (int i = (int) nodes.size() - 1; i >= 0; i--) {
                pair<TreeNode *, bool> node = nodes.front();
                nodes.pop();
                res += is_leaf(node.first) && node.second ? node.first->val : 0;
                if (node.first->left) {
                    nodes.push({node.first->left, true});
                }
                if (node.first->right) {
                    nodes.push({node.first->right, false});
                }
            }
        }
        return res;
    }
};