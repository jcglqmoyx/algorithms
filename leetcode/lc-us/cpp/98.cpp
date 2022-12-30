struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    bool flag = true;
    long long prev = -2147483649LL;

    void inorder(TreeNode *root) {
        if (!root) {
            return;
        }
        inorder(root->left);
        if (prev != -2147483649) {
            if (root->val <= prev) {
                flag = false;
                return;
            }
        }
        prev = root->val;
        inorder(root->right);
    }

public:
    bool isValidBST(TreeNode *root) {
        inorder(root);
        return flag;
    }
};