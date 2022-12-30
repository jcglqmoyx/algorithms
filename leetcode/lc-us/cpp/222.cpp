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
    int countNodes(TreeNode *root) {
        if (!root) return 0;
        int level = 0;
        auto node = root;
        while (node) {
            level++;
            node = node->left;
        }
        int low = 1 << (level - 1), high = (1 << level) - 1;
        while (low < high) {
            int mid = low + (high - low + 1) / 2;
            if (exsits(root, level, mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }

private:
    bool exsits(TreeNode *root, int level, int k) {
        TreeNode *node = root;
        int bits = 1 << (level - 2);
        while (node && bits) {
            if (bits & k) {
                node = node->right;
            } else {
                node = node->left;
            }
            bits >>= 1;
        }
        return node;
    }
};