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
    TreeNode *increasingBST(TreeNode *root) {
        dummy = new TreeNode, node = dummy;
        dfs(root);
        return dummy->right;
    }

private:
    TreeNode *dummy, *node;

    void dfs(TreeNode *root) {
        if (!root) return;
        dfs(root->left);
        node->right = root;
        node = node->right;
        node->left = nullptr;
        dfs(root->right);
    }
};