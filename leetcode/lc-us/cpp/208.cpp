#include <bits/stdc++.h>

using namespace std;

class Trie {
public:
    Trie() {
        end = false;
        memset(next, 0, sizeof(next));
    }

    void insert(string word) {
        auto node = this;
        for (char c: word) {
            if (!node->next[c - 'a']) {
                node->next[c - 'a'] = new Trie();
            }
            node = node->next[c - 'a'];
        }
        node->end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto node = this;
        for (char c: word) {
            if (!node->next[c - 'a']) {
                return false;
            }
            node = node->next[c - 'a'];
        }
        return node->end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto node = this;
        for (char c: prefix) {
            if (!node->next[c - 'a']) {
                return false;
            }
            node = node->next[c - 'a'];
        }
        return true;
    }

private:
    bool end;
    Trie *next[26];
};