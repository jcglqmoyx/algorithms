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
    int findBottomLeftValue(TreeNode *root) {
        queue<TreeNode *> nodes;
        nodes.push(root);
        int bottom_left_value = 0;
        while (!nodes.empty()) {
            bottom_left_value = nodes.front()->val;
            for (int i = (int) nodes.size(); i > 0; i--) {
                TreeNode *node = nodes.front();
                nodes.pop();
                if (node->left) {
                    nodes.push(node->left);
                }
                if (node->right) {
                    nodes.push(node->right);
                }
            }
        }
        return bottom_left_value;
    }
};