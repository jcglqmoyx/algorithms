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
    TreeNode *findNearestRightNode(TreeNode *root, TreeNode *u) {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            for (auto it = q.size(); it; it--) {
                TreeNode *node = q.front();
                q.pop();
                if (node == u) {
                    if (it == 1) {
                        return nullptr;
                    } else {
                        return q.front();
                    }
                }
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return nullptr;
    }
};