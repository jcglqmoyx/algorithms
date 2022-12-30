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
    bool isCompleteTree(TreeNode *root) {
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        int last = -1;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            int idx = t.second;
            if (idx != last + 1) return false;
            if (t.first->left) q.push({t.first->left, (idx << 1) + 1});
            if (t.first->right) q.push({t.first->right, (idx + 1) << 1});
            last = idx;
        }
        return true;
    }
};