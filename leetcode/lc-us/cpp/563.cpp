struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int tilt = 0;

    int traverse(TreeNode *node) {
        if (!node) return 0;
        int l = traverse(node->left);
        int r = traverse(node->right);
        tilt += l > r ? l - r : r - l;
        return l + r + node->val;
    }

public:
    int findTilt(TreeNode *root) {
        traverse(root);
        return tilt;
    }
};
