struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int ans = 1;

    int depth(TreeNode *node) {
        if (!node) return 0;
        int l = depth(node->left);
        int r = depth(node->right);
        if (l + r + 1 > ans) ans = l + r + 1;
        return l > r ? l + 1 : r + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode *root) {
        depth(root);
        return ans - 1;
    }
};