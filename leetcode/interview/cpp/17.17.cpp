#include <bits/stdc++.h>

using namespace std;

class Solution {
    struct Trie {
        vector<int> src;
        Trie *next[26];

        Trie() {
            for (int i = 0; i <= 25; i++) {
                this->next[i] = nullptr;
            }
        }
    };

    Trie *root = new Trie();

    void add(const string &word, int idx) {
        Trie *node = root;
        for (auto c: word) {
            int v = c - 'a';
            if (!node->next[v]) {
                node->next[v] = new Trie();
            }
            node = node->next[v];
            node->src.emplace_back(idx);
        }
    }

    vector<int> find(const string &word) {
        Trie *node = root;
        for (auto c: word) {
            int v = c - 'a';
            node = node->next[v];
            if (!node) return vector<int>{};
        }
        return node->src;
    }

public:
    vector<vector<int>> multiSearch(string big, vector<string> &smalls) {
        for (int i = 0; i < big.size(); i++) {
            add(big.substr(i), i);
        }
        vector<vector<int>> res;
        for (const string &word: smalls) {
            res.emplace_back(find(word));
        }
        return res;
    }
};