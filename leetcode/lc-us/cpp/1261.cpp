#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class FindElements {
    unordered_set<int> nums;

    void recover(TreeNode *root, int val) {
        if (!root) return;
        root->val = val;
        nums.insert(val);
        recover(root->left, 2 * val + 1);
        recover(root->right, 2 * val + 2);
    }

public:
    FindElements(TreeNode *root) {
        nums.insert(0);
        recover(root->left, 1);
        recover(root->right, 2);
    }

    bool find(int target) {
        return nums.count(target);
    }
};