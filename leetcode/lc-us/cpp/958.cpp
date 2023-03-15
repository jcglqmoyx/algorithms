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
        q.push({root, 1});
        int last = 1, cnt = 0;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            last = t.second, cnt++;
            if (last > cnt) return false;
            if (t.first->left) q.push({t.first->left, t.second * 2});
            if (t.first->right) q.push({t.first->right, t.second * 2 + 1});
        }
        return cnt == last;
    }
};