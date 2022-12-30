#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node *random;

    Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}

    Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}

    Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
};

class Solution {
    unordered_map<Node *, NodeCopy *> map;
public:
    NodeCopy *copyRandomBinaryTree(Node *root) {
        if (!root) return nullptr;
        if (map.count(root)) return map[root];
        NodeCopy *node = new NodeCopy(root->val);
        map[root] = node;
        node->random = copyRandomBinaryTree(root->random);
        node->left = copyRandomBinaryTree(root->left);
        node->right = copyRandomBinaryTree(root->right);
        return node;
    }
};