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
    int equalToDescendants(TreeNode *root) {
        sum = 0;
        dfs(root);
        return sum;
    }

private:
    using LL = long long;
    int sum;

    LL dfs(TreeNode *node) {
        if (!node) return 0;
        LL l = dfs(node->left), r = dfs(node->right);
        if (l + r == node->val) sum++;
        return l + r + node->val;
    }
};