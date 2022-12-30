#include <bits/stdc++.h>

using namespace std;

class Trie {
public:
    bool is_end;
    Trie *next[26];

    Trie() : is_end(false), next() {}

    string search(string &key) {
        Trie *node = this;
        for (int i = 0; i < key.length(); i++) {
            if (!node->next[key[i] - 'a']) return "";
            node = node->next[key[i] - 'a'];
            if (node->is_end) return key.substr(0, i + 1);
        }
        return "";
    }

    void insert(string &key) {
        Trie *node = this;
        for (char c: key) {
            if (!node->next[c - 'a']) {
                node->next[c - 'a'] = new Trie();
            }
            node = node->next[c - 'a'];
        }
        node->is_end = true;
    }
};

class Solution {
public:
    string replaceWords(vector<string> &dictionary, string sentence) {
        Trie *trie = new Trie();
        vector<string> words;
        stringstream ss;
        ss << sentence;
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        for (string &w: dictionary) {
            trie->insert(w);
        }
        string res;
        for (string &w: words) {
            string search_result = trie->search(w);
            res += search_result.empty() ? w + " " : search_result + " ";
        }
        res.pop_back();
        delete trie;
        return res;
    }
};