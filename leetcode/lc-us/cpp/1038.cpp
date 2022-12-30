struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int prev = 0;

    void inorder(TreeNode *root) {
        if (!root) {
            return;
        }
        inorder(root->right);
        root->val += prev;
        prev = root->val;
        inorder(root->left);
    }

public:
    TreeNode *bstToGst(TreeNode *root) {
        inorder(root);
        return root;
    }
};