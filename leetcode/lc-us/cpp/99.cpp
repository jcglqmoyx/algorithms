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
    void recoverTree(TreeNode *root) {
        TreeNode *first = nullptr, *second = nullptr, *last = nullptr;
        while (root) {
            if (!root->left) {
                if (last && last->val > root->val) {
                    if (!first) first = last, second = root;
                    else second = root;
                }
                last = root;
                root = root->right;
            } else {
                auto p = root->left;
                while (p->right && p->right != root) p = p->right;
                if (!p->right) p->right = root, root = root->left;
                else {
                    p->right = nullptr;
                    if (last && last->val > root->val) {
                        if (!first) first = last, second = root;
                        else second = root;
                    }
                    last = root;
                    root = root->right;
                }
            }
        }
        swap(first->val, second->val);
    }
};