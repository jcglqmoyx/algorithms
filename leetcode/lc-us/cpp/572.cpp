struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    bool flag = false;

    void dfs(TreeNode *s, TreeNode *t) {
        if (!s) {
            return;
        }
        bool is_subtree = cmp(s, t);
        if (is_subtree) {
            flag = true;
        }
        dfs(s->left, t);
        dfs(s->right, t);
    }

    bool cmp(TreeNode *s, TreeNode *t) {
        if (!s && !t) {
            return true;
        } else if (!s || !t || s->val != t->val) {
            return false;
        }
        return cmp(s->left, t->left) && cmp(s->right, t->right);
    }

public:
    bool isSubtree(TreeNode *s, TreeNode *t) {
        dfs(s, t);
        return flag;
    }
};