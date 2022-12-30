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
        for (Node *node: root->children) {
            dfs(node);
        }
        res.push_back(root->val);
    }

public:
    vector<int> postorder(Node *root) {
        dfs(root);
        return res;
    }
};