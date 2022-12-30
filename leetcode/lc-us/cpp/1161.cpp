#include <queue>

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
    int maxLevelSum(TreeNode *root) {
        int level = 0;
        int res = 0;
        int max_sum = INT32_MIN;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            level++;
            int sum = 0;
            for (auto it = q.size(); it; it--) {
                auto node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                sum += node->val;
            }
            if (sum > max_sum) {
                max_sum = sum;
                res = level;
            }
        }
        return res;
    }
};