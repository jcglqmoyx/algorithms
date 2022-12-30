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
    TreeNode *r;
    queue<TreeNode *> q;
    deque<TreeNode *> dq;

public:
    CBTInserter(TreeNode *root) {
        r = root;
        q.push(root);
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (!t->left || !t->right) dq.push_back(t);
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
        }
    }

    int insert(int v) {
        auto t = dq.front();
        auto last = new TreeNode(v);
        if (!t->left) {
            t->left = last;
        } else if (!t->right) {
            t->right = last;
        }
        if (t->left && t->right) dq.pop_front();
        dq.push_back(last);
        return t->val;
    }

    TreeNode *get_root() {
        return r;
    }
};