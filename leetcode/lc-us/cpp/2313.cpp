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
    int minimumFlips(TreeNode *root, bool result) {
        auto t = dp(root);
        if (result) return t.one;
        else return t.zero;
    }

private:
    struct T {
        int zero, one;
        int val;
    };

    T dp(TreeNode *node) {
        if (!node) {
            return {0, 0, 0};
        } else if (node->val == 0) {
            return {0, 1, 0};
        } else if (node->val == 1) {
            return {1, 0, 1};
        } else {
            int a = 1e8, b = 1e8;
            int val;
            auto l = dp(node->left), r = dp(node->right);
            switch (node->val) {
                case 2:
                    if (l.val | r.val) a = l.zero + r.zero, b = 0;
                    else a = l.zero + r.zero, b = min(l.one, r.one);
                    val = l.val | r.val;
                    break;
                case 3:
                    if (l.val & r.val) a = min(l.zero, r.zero), b = 0;
                    else a = 0, b = l.one + r.one;
                    val = l.val & r.val;
                    break;
                case 4:
                    if (l.val ^ r.val) a = min(l.zero + r.zero, l.one + r.one), b = 0;
                    else a = 0, b = min(l.zero + r.one, l.one + r.zero);
                    val = l.val ^ r.val;
                    break;
                case 5:
                    if (node->left) a = l.one, b = l.zero, val = !l.val;
                    else a = r.one, b = r.zero, val = !r.val;
            }
            return {a, b, val};
        }
    }
};