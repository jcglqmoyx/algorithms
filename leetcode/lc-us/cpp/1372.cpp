#include <unordered_map>

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
    int longestZigZag(TreeNode *root) {
        res = 0;
        dfs(root);
        return res;
    }

private:
    using PII = pair<int, int>;
    int res;

    PII dfs(TreeNode *root) {
        if (!root) return {-1, -1};
        int l = dfs(root->left).second + 1;
        int r = dfs(root->right).first + 1;
        res = max(res, max(l, r));
        return {l, r};
    }
};