#include <vector>

using namespace std;

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
    vector<vector<int>> findLeaves(TreeNode *root) {
        dfs(root);
        return leaves;
    }

private:
    vector<vector<int>> leaves;

    int dfs(TreeNode *root) {
        if (!root) return -1;
        int l = dfs(root->left);
        int r = dfs(root->right);
        int depth = max(l, r) + 1;
        if (depth >= leaves.size()) leaves.emplace_back();
        leaves[depth].push_back(root->val);
        return depth;
    }
};