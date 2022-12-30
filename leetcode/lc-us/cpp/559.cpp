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
    int max_depth = 0;

    void dfs(Node *root, int depth) {
        if (!root) {
            return;
        }
        max_depth = max(max_depth, depth);
        for (Node *child: root->children) {
            dfs(child, depth + 1);
        }
    }

public:
    int maxDepth(Node *root) {
        dfs(root, 1);
        return max_depth;
    }
};