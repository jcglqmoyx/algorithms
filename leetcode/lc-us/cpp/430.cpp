#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution {
    vector<Node *> dfs(Node *node) {
        auto cur = node, tail = node;
        while (cur) {
            tail = cur;
            if (cur->child) {
                auto t = dfs(cur->child);
                cur->child = nullptr;
                auto next = cur->next;
                t[1]->next = next;
                if (next) next->prev = t[1];
                cur->next = t[0];
                t[0]->prev = cur;
                cur = cur->next;
                tail = t[1];
            } else {
                cur = cur->next;
            }
        }
        return {node, tail};
    }

public:
    Node *flatten(Node *head) {
        return dfs(head)[0];
    }
};