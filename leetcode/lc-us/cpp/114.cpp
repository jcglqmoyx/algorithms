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
    void flatten(TreeNode *root) {
        TreeNode *cur = root;
        while (cur) {
            if (cur->left) {
                TreeNode *left = cur->left, *predecessor = cur->left, *right = cur->right;
                while (predecessor && predecessor->right) {
                    predecessor = predecessor->right;
                }
                predecessor->right = right;
                cur->left = nullptr;
                cur->right = left;
            }
            cur = cur->right;
        }
    }
};