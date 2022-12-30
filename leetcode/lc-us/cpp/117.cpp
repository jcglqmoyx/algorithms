#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next) : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node *connect(Node *root) {
        auto res = root;
        while (root) {
            Node *next_start = nullptr;
            Node *temp = nullptr;
            bool next_start_existed = false;
            for (Node *node = root; node; node = node->next) {
                if (node->left) {
                    if (!next_start_existed) {
                        next_start_existed = true;
                        next_start = node->left;
                        temp = next_start;
                    } else {
                        temp->next = node->left;
                        temp = temp->next;
                    }
                }
                if (node->right) {
                    if (!next_start_existed) {
                        next_start_existed = true;
                        next_start = node->right;
                        temp = next_start;
                    } else {
                        temp->next = node->right;
                        temp = temp->next;
                    }
                }
            }
            root = next_start;
        }
        return res;
    }
};