#include <bits/stdc++.h>

using namespace std;

struct Trie {
    bool is_end;
    Trie *next[26];

    Trie() : is_end(false), next() {}

    void insert(string &w) {
        Trie *trie = this;
        for (char c: w) {
            int idx = c - 'a';
            if (!trie->next[idx]) trie->next[idx] = new Trie();
            trie = trie->next[idx];
        }
        trie->is_end = true;
    }

    bool query(string &w) {
        Trie *trie = this;
        for (char c: w) {
            if (!trie->next[c - 'a']->is_end) return false;
            trie = trie->next[c - 'a'];
        }
        return true;
    }
};

class Solution {
public:
    string longestWord(vector<string> &words) {
        auto trie = new Trie();
        for (string &w: words) {
            trie->insert(w);
        }
        string res;
        for (string &w: words) {
            if (trie->query(w)) {
                if (w.length() > res.length()) {
                    res = w;
                } else if (w.length() == res.length()) {
                    if (w < res) {
                        res = w;
                    }
                }
            }
        }
        return res;
    }
};