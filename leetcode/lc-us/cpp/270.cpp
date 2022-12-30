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
    double min_diff = (double) INT32_MAX * 2;
    int ans = 0;

    double absolute_value(double n) {
        return n > 0 ? n : -n;
    }

    int closestValue(TreeNode *root, double target) {
        if (!root) return ans;
        double val = root->val;
        double diff = absolute_value(val - target);
        if (diff <= min_diff) {
            min_diff = diff;
            ans = root->val;
        }
        if (val > target) return closestValue(root->left, target);
        else return closestValue(root->right, target);
    }
};