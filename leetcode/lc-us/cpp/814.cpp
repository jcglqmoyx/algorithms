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
    TreeNode *pruneTree(TreeNode *root) {
        return contains_one(root) ? root : nullptr;
    }

private:
    bool contains_one(TreeNode *node) {
        if (!node) return false;
        bool l = contains_one(node->left), r = contains_one(node->right);
        if (!l) node->left = nullptr;
        if (!r) node->right = nullptr;
        return node->val == 1 || l || r;
    }
};