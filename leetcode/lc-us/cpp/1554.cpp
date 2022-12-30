#include <bits/stdc++.h>

using namespace std;

class Trie {
    bool is_end;
    Trie *next[26];
public:
    Trie() : is_end(false), next() {}

    void add(string &key) {
        Trie *trie = this;
        for (char c: key) {
            if (!trie->next[c - 'a']) {
                trie->next[c - 'a'] = new Trie();
            }
            trie = trie->next[c - 'a'];
        }
        trie->is_end = true;
    }

    bool query(string &key, Trie *node, int index, int count) {
        if (!node || count > 1) return false;
        if (index == key.length() && node->is_end && count == 1) return true;
        if (node->next[key[index] - 'a']) {
            if (query(key, node->next[key[index] - 'a'], index + 1, count)) {
                return true;
            }
        }
        for (auto &i: node->next) {
            if (query(key, i, index + 1, count + 1)) {
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool differByOne(vector<string> &dict) {
        Trie *trie = new Trie();
        for (string &word: dict) {
            if (trie->query(word, trie, 0, 0)) {
                return true;
            }
            trie->add(word);
        }
        return false;
    }
};