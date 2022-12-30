struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int prev = -10001;

    void inorder(TreeNode *root) {
        if (!root) return;
        inorder(root->right);
        if (prev != -10001) {
            root->val += prev;
        }
        prev = root->val;
        inorder(root->left);
    }

public:
    TreeNode *convertBST(TreeNode *root) {
        inorder(root);
        return root;
    }
};