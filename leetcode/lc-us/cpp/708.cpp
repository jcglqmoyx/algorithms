#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node *next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node *_next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    Node *insert(Node *head, int insertVal) {
        if (!head) {
            auto node = new Node(insertVal);
            node->next = node;
            return node;
        }
        auto cur = head, mn = head, mx = head;
        do {
            if (cur->next->val < mn->val) {
                mn = cur->next;
            }
            if (cur->next->val >= mx->val) mx = cur->next;
            if (cur->val <= insertVal && cur->next->val >= insertVal) {
                cur->next = new Node(insertVal, cur->next);
                return head;
            }
            cur = cur->next;
        } while (cur != head);
        if (insertVal >= mx->val) {
            mx->next = new Node(insertVal, mx->next);
        } else if (insertVal <= mn->val) {
            if (mn == mx) {
                mn->next = new Node(insertVal, mn->next);
            } else {
                mx->next = new Node(insertVal, mn);
            }
        }
        return head;
    }
};