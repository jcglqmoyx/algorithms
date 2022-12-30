struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int count = 0;
    int res = 0;

    void inorder(TreeNode *root, int k) {
        if (!root) return;
        inorder(root->left, k);
        count++;
        if (count == k) {
            res = root->val;
            return;
        }
        inorder(root->right, k);
    }

public:
    int kthSmallest(TreeNode *root, int k) {
        inorder(root, k);
        return res;
    }
};