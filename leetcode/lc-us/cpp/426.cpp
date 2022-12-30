#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
    Node *head, *tail;
    Node *prev;

    void inorder(Node *node) {
        if (!node) return;
        inorder(node->left);
        if (!node->left && !head) {
            head = node;
        }
        if (!node->right) {
            tail = node;
        }
        if (prev) {
            prev->right = node;
            node->left = prev;
        }
        prev = node;
        inorder(node->right);
    }

public:
    Node *treeToDoublyList(Node *root) {
        if (!root) return nullptr;
        inorder(root);
        head->left = tail;
        tail->right = head;
        return head;
    }
};