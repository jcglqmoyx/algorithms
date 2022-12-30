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
    TreeNode *reverseOddLevels(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        int level = -1;
        while (!q.empty()) {
            level++;
            vector<TreeNode *> v;
            for (auto it = q.size(); it; it--) {
                auto t = q.front();
                q.pop();
                v.push_back(t);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            if (level & 1) {
                for (int l = 0, r = (int) v.size() - 1; l < r; l++, r--) {
                    swap(v[l]->val, v[r]->val);
                }
            }
        }
        return root;
    }
};