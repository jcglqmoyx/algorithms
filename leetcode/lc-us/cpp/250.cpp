struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int res = 0;

    bool dfs(TreeNode *root) {
        if (!root->left && !root->right) {
            res++;
            return true;
        }
        bool flag = true;
        if (root->left && !(dfs(root->left) && root->val == root->left->val)) {
            flag = false;
        }
        if (root->right && !(dfs(root->right) && root->val == root->right->val)) {
            flag = false;
        }
        if (flag) {
            res++;
        } else {
            return false;
        }
        return true;
    }

public:
    int countUnivalSubtrees(TreeNode *root) {
        if (!root) return 0;
        dfs(root);
        return res;
    }
};