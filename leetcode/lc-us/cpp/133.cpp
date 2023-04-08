#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    vector<Node *> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
    unordered_map<Node *, Node *> visited;

public:
    Node *cloneGraph(Node *node) {
        if (!node) return node;
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }
        auto clone_node = new Node(node->val);
        visited[node] = clone_node;
        for (auto &neighbor: node->neighbors) {
            clone_node->neighbors.push_back(cloneGraph(neighbor));
        }
        return clone_node;
    }
};