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
    int widthOfBinaryTree(TreeNode *root) {
        int max_width = 1;
        queue<pair<TreeNode *, long long>> q;
        q.push({root, 1});
        while (!q.empty()) {
            long long l, r;
            int size = (int) q.size();
            for (int i = size; i; i--) {
                auto t = q.front();
                if (i == size) l = t.second;
                if (i == 1) r = t.second;
                q.pop();
                if (t.first->left) q.push({t.first->left, t.second * 2 - l});
                if (t.first->right) q.push({t.first->right, t.second * 2 + 1 - l});
            }
            max_width = max(max_width, (int) (r - l + 1));
        }
        return max_width;
    }
};