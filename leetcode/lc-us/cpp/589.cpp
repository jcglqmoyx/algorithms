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
    vector<int> res;

    void dfs(Node *root) {
        if (!root) {
            return;
        }
        res.push_back(root->val);
        if (!root->children.empty()) {
            for (Node *node: root->children) {
                dfs(node);
            }
        }
    }

public:
    vector<int> preorder(Node *root) {
        dfs(root);
        return res;
    }
};