#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
    unordered_map<Node *, Node *> visited;
public:
    Node *copyRandomList(Node *head) {
        if (!head) return nullptr;
        if (visited.find(head) != visited.end()) return visited[head];
        auto node = new Node(head->val);
        visited[head] = node;
        node->next = copyRandomList(head->next);
        node->random = copyRandomList(head->random);
        return node;
    }
};