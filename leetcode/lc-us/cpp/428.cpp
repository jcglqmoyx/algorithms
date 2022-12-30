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

class Codec {
    void dfs1(Node *root, string &s) {
        s += to_string(root->val);
        s.push_back('(');
        for (Node *child: root->children) {
            dfs1(child, s);
        }
        s.push_back(')');
    }

    Node *dfs2(string &s, int &u) {
        if (s[u] == ')') return nullptr;
        int x = 0;
        while (isdigit(s[u])) {
            x = x * 10 + s[u] - '0';
            u++;
        }
        u++;
        auto root = new Node(x);
        vector<Node *> children;
        while (true) {
            auto t = dfs2(s, u);
            if (t) children.push_back(t);
            else break;
            u++;
        }
        root->children = children;
        return root;
    }

public:
    string serialize(Node *root) {
        if (!root) return "";
        string s;
        dfs1(root, s);
        return s;
    }

    Node *deserialize(string data) {
        if (data.empty()) return nullptr;
        int u = 0;
        return dfs2(data, u);
    }
};