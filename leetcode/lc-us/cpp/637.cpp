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
    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> res;
        queue<TreeNode *> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            double sum = 0;
            int size = (int) nodes.size();
            for (int i = size; i > 0; i--) {
                TreeNode *node = nodes.front();
                nodes.pop();
                sum += node->val;
                if (node->left) {
                    nodes.push(node->left);
                }
                if (node->right) {
                    nodes.push(node->right);
                }
            }
            res.push_back(sum / size);
        }
        return res;
    }
};