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
        if (!head) return head;
        if (visited.count(head)) return visited[head];
        Node *copy = new Node(head->val);
        visited[head] = copy;
        copy->next = copyRandomList(head->next);
        copy->random = copyRandomList(head->random);
        return copy;
    }
};