#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    TreeNode *encode(Node *root) {
        if (!root) return nullptr;
        auto r = new TreeNode(root->val);
        if (root->children.empty()) return r;
        r->left = encode(root->children[0]);
        auto c = r->left;
        for (int i = 1; i < root->children.size(); i++) {
            c->right = encode(root->children[i]);
            c = c->right;
        }
        return r;
    }

    Node *decode(TreeNode *root) {
        if (!root) return nullptr;
        auto r = new Node(root->val);
        if (!root->left) return r;
        vector<Node *> children;
        auto p = root->left;
        while (p) {
            children.push_back(decode(p));
            p = p->right;
        }
        r->children = children;
        return r;
    }
};