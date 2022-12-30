#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
    void dfs(Node *node, Node *target, Node *&parent, int &flag) {
        for (int i = 0; i < node->children.size(); i++) {
            if (node->children[i] == target) {
                flag++;
                parent = node;
            }
            dfs(node->children[i], target, parent, flag);
        }
    }

public:
    Node *moveSubTree(Node *root, Node *p, Node *q) {
        int flag = 0;
        Node *pp, *pq;
        auto dummy = new Node(-1);
        dummy->children.push_back(root);

        dfs(p, q, pq, flag);
        dfs(dummy, p, pp, flag);
        if (flag == 2) {
            for (int i = 0; i < p->children.size(); i++) {
                if (p->children[i] == q) {
                    for (auto &child: pp->children) {
                        if (child == p) {
                            child = q;
                            break;
                        }
                    }
                    p->children.erase(p->children.begin() + i);
                    q->children.push_back(p);
                    auto res = dummy->children[0];
                    delete dummy;
                    return res;
                }
            }
            pq->children.erase(std::find(pq->children.begin(), pq->children.end(), q));
            for (auto &child: pp->children) {
                if (child == p) {
                    child = q;
                    break;
                }
            }
            q->children.push_back(p);
            auto res = dummy->children[0];
            delete dummy;
            return res;
        } else if (!q->children.empty()) {
            for (auto child: q->children) {
                if (child == p) {
                    auto res = dummy->children[0];
                    delete dummy;
                    return res;
                }
            }
        }
        pp->children.erase(std::find(pp->children.begin(), pp->children.end(), p));
        q->children.push_back(p);
        auto res = dummy->children[0];
        delete dummy;
        return res;
    }
};