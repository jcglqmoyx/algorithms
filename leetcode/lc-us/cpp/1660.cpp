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
    TreeNode *correctBinaryTree(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        unordered_set<TreeNode *> set;
        while (!q.empty()) {
            set.clear();
            for (auto it = q.size(); it; it--) {
                TreeNode *node = q.front();
                q.pop();
                if (node->right) {
                    if (set.count(node->right->right)) {
                        node->right = nullptr;
                        return root;
                    } else {
                        q.push(node->right);
                        set.insert(node->right);
                    }
                }
                if (node->left) {
                    if (set.count(node->left->right)) {
                        node->left = nullptr;
                        return root;
                    } else {
                        q.push(node->left);
                        set.insert(node->left);
                    }
                }
            }
        }
        return root;
    }
};