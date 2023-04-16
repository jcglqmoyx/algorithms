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
    TreeNode *replaceValueInTree(TreeNode *root) {
        root->val = 0;
        vector<TreeNode *> q = {root};
        while (!q.empty()) {
            vector<TreeNode *> next_level;
            int next_level_sum = 0;
            for (auto node: q) {
                if (node->left) next_level.push_back(node->left), next_level_sum += node->left->val;
                if (node->right) next_level.push_back(node->right), next_level_sum += node->right->val;
            }
            for (auto node: q) {
                int child_sum = (node->left ? node->left->val : 0) + (node->right ? node->right->val : 0);
                if (node->left) node->left->val = next_level_sum - child_sum;
                if (node->right) node->right->val = next_level_sum - child_sum;
            }
            q = std::move(next_level);
        }
        return root;
    }
};