#include <bits/stdc++.h>

using namespace std;

struct Trie {
public:
    Trie *root;
    Trie *next[26];
    bool is_end;

    Trie() : root(nullptr), next(), is_end(false) {}

    void insert(string &word) {
        Trie *node = this;
        for (char c: word) {
            if (!node->next[c - 'a']) {
                node->next[c - 'a'] = new Trie();
            }
            node = node->next[c - 'a'];
        }
        node->is_end = true;
    }
};

class Solution {
    void dfs(Trie *trie, string &result, vector<string> &results) {
        if (results.size() >= 3) return;
        if (trie->is_end) {
            results.push_back(result);
        }
        for (int i = 0; i < 26; i++) {
            if (trie->next[i]) {
                result.push_back('a' + i);
                dfs(trie->next[i], result, results);
                result.pop_back();
            }
        }
    }

public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord) {
        int n = (int) searchWord.size();
        vector<vector<string>> suggested_products;
        Trie *trie = new Trie();
        for (string &product: products) trie->insert(product);
        for (int i = 0; i < n; i++) {
            string prefix = searchWord.substr(0, i + 1);
            vector<string> results;
            Trie *node = trie;
            bool not_empty = true;
            for (char c: prefix) {
                if (!node->next[c - 'a']) {
                    not_empty = false;
                    break;
                }
                node = node->next[c - 'a'];
            }
            if (not_empty) {
                dfs(node, prefix, results);
            }
            suggested_products.push_back(results);
        }
        return suggested_products;
    }
};