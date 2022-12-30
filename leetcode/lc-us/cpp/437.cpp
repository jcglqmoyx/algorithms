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
    unordered_map<long long, int> cnt;
    int res = 0;

    void dfs(TreeNode *root, int target, long long cur) {
        if (!root) return;
        cur += root->val;
        res += cnt[cur - target];
        cnt[cur]++;
        dfs(root->left, target, cur);
        dfs(root->right, target, cur);
        cnt[cur]--;
    }

public:
    int pathSum(TreeNode *root, int targetSum) {
        cnt[0] = 1;
        dfs(root, targetSum, 0);
        return res;
    }
};