#include <bits/stdc++.h>

using namespace std;

struct Trie {
    bool is_end;
    Trie *next[26];

    Trie() : is_end(false), next() {}

    void insert(string &s) {
        Trie *node = this;
        for (char c: s) {
            int idx = c - 'a';
            if (!node->next[idx]) node->next[idx] = new Trie();
            node = node->next[idx];
        }
        node->is_end = true;
    }
};

class StreamChecker {
    int max_length;
    string s;
    Trie *trie;
public:
    StreamChecker(vector<string> &words) {
        max_length = 0;
        trie = new Trie();
        for (string &w: words) {
            reverse(w.begin(), w.end());
            max_length = max(max_length, (int) w.size());
            trie->insert(w);
        }
    }

    bool query(char letter) {
        s.push_back(letter);
        auto node = trie;
        for (int i = (int) s.size() - 1; ~i && (int) s.size() - i <= max_length; i--) {
            int idx = s[i] - 'a';
            if (!node->next[idx]) return false;
            if (node->next[idx]->is_end) return true;
            node = node->next[idx];
        }
        return false;
    }
};