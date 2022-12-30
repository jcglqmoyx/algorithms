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
    unordered_map<Node *, Node *> map;
public:
    Node *cloneTree(Node *root) {
        if (!root) return nullptr;
        if (map.count(root)) return map[root];
        auto node = new Node(root->val);
        map[root] = node;
        for (Node *child: root->children) {
            node->children.push_back(cloneTree(child));
        }
        return node;
    }
};