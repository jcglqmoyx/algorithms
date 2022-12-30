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
    vector<int> largestValues(TreeNode *root) {
        vector<int> largest_values;
        if (!root) return largest_values;
        queue<TreeNode *> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            int largest_value = INT32_MIN;
            for (int i = nodes.size(); i > 0; i--) {
                TreeNode *node = nodes.front();
                nodes.pop();
                largest_value = max(largest_value, node->val);
                if (node->left) nodes.push(node->left);
                if (node->right) nodes.push(node->right);
            }
            largest_values.push_back(largest_value);
        }
        return largest_values;
    }
};