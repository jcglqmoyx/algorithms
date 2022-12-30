#include <bits/stdc++.h>

using namespace std;

class MapSum {
public:
    MapSum() {
        this->trie = new Trie;
    }

    void insert(string key, int val) {
        this->trie->insert(key, val);
    }

    int sum(string prefix) {
        return this->trie->search(prefix);
    }

private:
    struct Trie {
        int cnt;
        Trie *next[26];

        Trie() : cnt(0), next() {}

        void insert(string &s, int val) {
            auto t = this;
            for (char c : s) {
                if (!t->next[c - 'a']) {
                    t->next[c - 'a'] = new Trie;
                }
                t = t->next[c - 'a'];
            }
            t->cnt = val;
        }

        int search(string &prefix) {
            auto t = this;
            for (char c : prefix) {
                if (!t->next[c - 'a']) return 0;
                t = t->next[c - 'a'];
            }
            return get_sum(t);
        }

        int get_sum(Trie *t) {
            int sum = t->cnt;
            for (auto &i : t->next) {
                if (i) {
                    sum += get_sum(i);
                }
            }
            return sum;
        }
    };

    Trie *trie;
};