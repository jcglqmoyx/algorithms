#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *parent;
};

class Solution {
public:
    Node *lowestCommonAncestor(Node *p, Node *q) {
        unordered_set<Node *> set;
        while (p) {
            set.insert(p);
            p = p->parent;
        }
        while (q) {
            if (set.count(q)) return q;
            q = q->parent;
        }
        return nullptr;
    }
};