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
    bool hasPathSum(TreeNode *root, int sum) {
        dfs(root, sum);
        return flag;
    }

private:
    bool flag = false;

    bool is_leaf(TreeNode *node) {
        return !node->left && !node->right;
    }

    void dfs(TreeNode *root, int left) {
        if (!root) return;
        if (is_leaf(root) && left - root->val == 0) {
            flag = true;
            return;
        }
        if (root->left) dfs(root->left, left - root->val);
        if (root->right) dfs(root->right, left - root->val);
    }
};