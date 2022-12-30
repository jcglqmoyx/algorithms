#include <bits/stdc++.h>

using namespace std;

class MapSum {
    class Trie {
    public:
        Trie *next[26];
        int val;

        Trie() {
            val = 0;
            memset(next, 0, sizeof(next));
        }

        void insert(string &s, int value) {
            Trie *p = this;
            for (char c: s) {
                if (!p->next[c - 'a']) p->next[c - 'a'] = new Trie();
                p = p->next[c - 'a'];
            }
            p->val = value;
        }

        int getVal() {
            int res = this->val;
            for (auto n: this->next) {
                if (n) res += n->getVal();
            }
            return res;
        }
    };

    Trie *node;
public:
    MapSum() {
        node = new Trie();
    }

    void insert(string key, int val) {
        node->insert(key, val);
    }

    int sum(string prefix) {
        Trie *p = node;
        for (char c: prefix) {
            if (!p->next[c - 'a']) return 0;
            p = p->next[c - 'a'];
        }
        return p->getVal();
    }
};