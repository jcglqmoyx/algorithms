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

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while (root) {
            stk.push(root);
            root = root->left;
        }
    }

    int next() {
        auto t = stk.top();
        stk.pop();
        if (t->right) {
            auto node = t->right;
            while (node) {
                stk.push(node);
                node = node->left;
            }
        }
        return t->val;
    }

    bool hasNext() {
        return !stk.empty();
    }

private:
    stack<TreeNode *> stk;
};