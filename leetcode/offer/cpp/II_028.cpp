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
public:
    Node *flatten(Node *head) {
        return dfs(head).first;
    }

private:
    pair<Node *, Node *> dfs(Node *cur) {
        if (!cur) return {nullptr, nullptr};
        auto head = cur, tail = cur;
        while (cur) {
            tail = cur;
            if (!cur->child) {
                cur = cur->next;
            } else {
                auto t = dfs(cur->child);
                cur->child = nullptr;
                t.second->next = cur->next;
                if (cur->next) cur->next->prev = t.second;
                cur->next = t.first;
                t.first->prev = cur;
                cur = t.second->next;
                tail = t.second;
            }
        }
        return {head, tail};
    }
};