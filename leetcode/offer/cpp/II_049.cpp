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
    int sumNumbers(TreeNode *root) {
        sum = 0;
        dfs(root, 0);
        return sum;
    }

private:
    int sum;

    void dfs(TreeNode *node, int cur) {
        if (!node) return;
        cur = cur * 10 + node->val;
        if (!node->left && !node->right) {
            sum += cur;
            return;
        }
        dfs(node->left, cur);
        dfs(node->right, cur);
    }
};