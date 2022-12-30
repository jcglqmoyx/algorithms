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

class Solution {
public:
    Node *findRoot(vector<Node *> tree) {
        int xor_sum = 0;
        for (const Node *node: tree) {
            xor_sum ^= node->val;
            for (const Node *child: node->children) {
                xor_sum ^= child->val;
            }
        }
        for (Node *node: tree) {
            if (node->val == xor_sum) {
                return node;
            }
        }
        return nullptr;
    }
};