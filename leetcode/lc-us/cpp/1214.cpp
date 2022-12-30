#include <unordered_set>

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
    bool flag;
    unordered_set<int> set;

    void query(TreeNode *root, int target) {
        if (!root) return;
        if (set.find(target - root->val) != set.end()) {
            flag = true;
            return;
        }
        query(root->left, target);
        query(root->right, target);
    }

    void inorder(TreeNode *root) {
        if (!root) return;
        inorder(root->left);
        set.insert(root->val);
        inorder(root->right);
    }

public:
    bool twoSumBSTs(TreeNode *root1, TreeNode *root2, int target) {
        flag = false;
        inorder(root2);
        query(root1, target);
        return flag;
    }
};