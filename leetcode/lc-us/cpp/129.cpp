struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int sum = 0;

    void dfs(TreeNode *root, int num) {
        if (!root) return;
        num = num * 10 + root->val;
        if (is_leaf(root)) sum += num;
        dfs(root->left, num);
        dfs(root->right, num);
    }

    bool is_leaf(TreeNode *node) {
        return !node->left && !node->right;
    }

public:
    int sumNumbers(TreeNode *root) {
        dfs(root, 0);
        return sum;
    }
};