struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int left, right;

    int dfs(TreeNode *root, int x) {
        if (!root) return 0;
        auto l = dfs(root->left, x), r = dfs(root->right, x);
        if (root->val == x) {
            left = l, right = r;
        }
        return l + r + 1;
    }

public:
    bool btreeGameWinningMove(TreeNode *root, int n, int x) {
        left = 0, right = 0;
        dfs(root, x);
        int up = n - left - right - 1;
        if (up > left + right || left > right + up || right > left + up) {
            return true;
        }
        return false;
    }
};