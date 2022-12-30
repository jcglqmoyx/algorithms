struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    TreeNode *prev;
    TreeNode *res;

    void inorder(TreeNode *root) {
        if (!root) {
            return;
        }
        inorder(root->left);
        root->left = nullptr;
        prev->right = root;
        prev = prev->right;
        inorder(root->right);
    }

public:
    TreeNode *increasingBST(TreeNode *root) {
        prev = new TreeNode(0), res = prev;
        inorder(root);
        return res->right;
    }
};