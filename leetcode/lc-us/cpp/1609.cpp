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
    bool isEvenOddTree(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        bool even = true;
        while (!q.empty()) {
            int prev = 0;
            for (auto it = q.size(); it; it--) {
                TreeNode *cur = q.front();
                q.pop();
                if (even && cur->val % 2 == 0 || !even && cur->val % 2 == 1) return false;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
                if (even && prev && prev >= cur->val || !even && prev && prev <= cur->val) return false;
                prev = cur->val;
            }
            even = !even;
        }
        return true;
    }
};