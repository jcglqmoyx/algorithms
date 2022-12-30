#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        return height(root) >= 0;
    }

private:
    int height(TreeNode *root) {
        if (!root) return 0;
        int left_height, right_height;
        if ((left_height = height(root->left)) == -1 || (right_height = height(root->right)) == -1 ||
            abs(left_height - right_height) > 1)
            return -1;
        return max(left_height, right_height) + 1;
    }
};