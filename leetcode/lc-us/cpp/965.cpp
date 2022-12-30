struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int prev;

    bool dfs(TreeNode *root) {
        bool left = root->left == nullptr || dfs(root->left);
        bool right = root->right == nullptr || dfs(root->right);
        return root->val == prev && left && right;
    }

public:
    bool isUnivalTree(TreeNode *root) {
        prev = root->val;
        return dfs(root);
    }
};