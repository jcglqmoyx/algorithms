#include <bits/stdc++.h>

using namespace std;

class Skiplist {
    static const int level = 8;

    struct Node {
        int val;
        vector<Node *> next;

        Node(int _val) : val(_val) {
            next.resize(level);
        }
    } *head;

    void find(int target, vector<Node *> &pre) {
        auto p = head;
        for (int i = level - 1; ~i; i--) {
            while (p->next[i] && p->next[i]->val < target) p = p->next[i];
            pre[i] = p;
        }
    }

public:
    Skiplist() {
        head = new Node(-1);
    }

    ~Skiplist() {
        delete head;
    }

    bool search(int target) {
        vector<Node *> pre(level);
        find(target, pre);
        auto p = pre[0]->next[0];
        return p && p->val == target;
    }

    void add(int num) {
        vector<Node *> pre(level);
        find(num, pre);
        auto node = new Node(num);
        for (int i = 0; i < level; i++) {
            node->next[i] = pre[i]->next[i];
            pre[i]->next[i] = node;
            if (rand() % 2) break;
        }
    }

    bool erase(int num) {
        vector<Node *> pre(level);
        find(num, pre);
        auto node = pre[0]->next[0];
        if (!node || node->val != num) return false;
        for (int i = 0; i < level && pre[i]->next[i] == node; i++) {
            pre[i]->next[i] = node->next[i];
        }
        delete node;
        return true;
    }
};