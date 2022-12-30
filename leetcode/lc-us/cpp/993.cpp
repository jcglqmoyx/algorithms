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
    void dfs(TreeNode *root, int depth, TreeNode *parent, unordered_map<int, pair<TreeNode *, int>> &map) {
        if (!root) {
            return;
        }
        map[root->val] = {parent, depth};
        dfs(root->left, depth + 1, root, map);
        dfs(root->right, depth + 1, root, map);
    }

public:
    bool isCousins(TreeNode *root, int x, int y) {
        if (!root || !root->left || !root->right) {
            return false;
        }
        unordered_map<int, pair<TreeNode *, int>> map;
        map[root->val] = {nullptr, 0};
        dfs(root, 0, nullptr, map);
        return map[x].first != map[y].first && map[x].second == map[y].second;
    }
};