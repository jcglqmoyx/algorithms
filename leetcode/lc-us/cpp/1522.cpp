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
    int res;

    int dfs(Node *root) {
        if (!root) return 0;
        vector<int> depth;
        int x = 0, y = 0;
        for (auto child: root->children) {
            depth.push_back(dfs(child));
        }
        sort(depth.begin(), depth.end(), greater<>());
        if (!depth.empty()) {
            x = depth.front();
            if (depth.size() > 1) {
                y = depth[1];
            }
        }
        res = max(res, x + y);
        return max(x, y) + 1;
    }

public:
    int diameter(Node *root) {
        res = 0;
        dfs(root);
        return res;
    }
};