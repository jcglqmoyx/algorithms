struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void dfs(TreeNode *&root, int sum, int limit) {
        if (!root) return;
        sum += root->val;
        if (!root->left && !root->right) {
            if (sum < limit) {
                root = nullptr;
            }
        } else {
            dfs(root->left, sum, limit);
            dfs(root->right, sum, limit);
            if (!root->left && !root->right) {
                root = nullptr;
            }
        }
    }

public:
    TreeNode *sufficientSubset(TreeNode *root, int limit) {
        dfs(root, 0, limit);
        return root;
    }
};