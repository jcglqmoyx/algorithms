class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *parent;
};

class Solution {
public:
    Node *flipBinaryTree(Node *root, Node *leaf) {
        return dfs(leaf);
    }

private:
    Node *dfs(Node *node) {
        if (!node || !node->parent) return node;
        auto p = node->parent, l = node->left;

        if (l) node->right = l;

        node->parent = nullptr;
        if (p->left == node) p->left = nullptr;
        else p->right = nullptr;

        node->left = dfs(p);
        p->parent = node;
        return node;
    }
};