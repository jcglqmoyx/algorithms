#include <bits/stdc++.h>

using namespace std;

class Trie {
    int cnt;
    Trie *next[26];

public:
    Trie() : cnt(0), next() {}

    ~Trie() {
        delete *next;
    }

    int query(string &s) {
        Trie *node = this;
        int res = 0;
        for (char c: s) {
            int idx = c - 'a';
            if (!node->next[idx]) break;
            res += node->next[idx]->cnt;
            node = node->next[idx];
        }
        return res;
    }

    void insert(string &s) {
        Trie *node = this;
        for (char c: s) {
            int idx = c - 'a';
            if (!node->next[idx]) {
                node->next[idx] = new Trie();
            }
            node->next[idx]->cnt++;
            node = node->next[idx];
        }
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string> &words) {
        int n = (int) words.size();
        Trie *trie = new Trie();
        for (auto &w: words) trie->insert(w);
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = trie->query(words[i]);
        }
        delete trie;
        return res;
    }
};