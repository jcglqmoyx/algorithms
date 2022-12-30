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
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return traverse(root->left, root->right);
    }

    bool traverse(TreeNode *left, TreeNode *right) {
        if (!left && !right) return true;
        else if (!left || !right || left->val != right->val) return false;
        return traverse(left->left, right->right) && traverse(left->right, right->left);
    }
};