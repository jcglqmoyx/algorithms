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

    void dfs(TreeNode *node, int max_ancestor) {
        if (!node) return;
        if (node->val >= max_ancestor) {
            max_ancestor = node->val;
            count++;
        }
        dfs(node->left, max_ancestor);
        dfs(node->right, max_ancestor);
    }

public:
    int goodNodes(TreeNode *root) {
        dfs(root, -10000);
        return count;
    }
};