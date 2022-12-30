struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int ans = 0;

    void dfs(TreeNode *node, int cur) {
        if (!node) return;
        if (!node->left && !node->right) {
            ans += (cur << 1) + node->val;
        }
        dfs(node->left, cur * 2 + node->val);
        dfs(node->right, cur * 2 + node->val);
    }

public:
    int sumRootToLeaf(TreeNode *root) {
        dfs(root, 0);
        return ans;
    }
};