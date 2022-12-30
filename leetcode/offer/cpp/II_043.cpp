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

class CBTInserter {
public:
    CBTInserter(TreeNode *root) {
        r = root;
        q.push(root);
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
            if (!t->left || !t->right) nodes.push(t);
        }
    }

    int insert(int v) {
        auto t = nodes.front();
        if (!t->left) {
            t->left = new TreeNode(v);
            nodes.push(t->left);
        } else {
            t->right = new TreeNode(v);
            nodes.pop();
            nodes.push(t->right);
        }
        return t->val;
    }

    TreeNode *get_root() {
        return r;
    }

private:
    TreeNode *r;
    queue<TreeNode *> q, nodes;
};