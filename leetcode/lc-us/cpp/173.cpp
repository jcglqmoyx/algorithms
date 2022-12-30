#include <stack>

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
    stack<TreeNode *> stk;
public:
    BSTIterator(TreeNode *root) {
        leftmost_inorder(root);
    }

    void leftmost_inorder(TreeNode *node) {
        while (node) {
            stk.push(node);
            node = node->left;
        }
    }

    int next() {
        TreeNode *head = stk.top();
        stk.pop();
        if (head->right) {
            leftmost_inorder(head->right);
        }
        return head->val;
    }

    bool hasNext() {
        return !stk.empty();
    }
};