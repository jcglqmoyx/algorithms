#include <bits/stdc++.h>

using namespace std;

class Trie {
    Trie *next[26];
    int count_start_with;
    int count_is_end;
public:
    Trie() {
        count_start_with = 0;
        count_is_end = 0;
        for (auto &i: next) {
            i = nullptr;
        }
    }

    void insert(string word) {
        auto node = this;
        for (char c: word) {
            if (!node->next[c - 'a']) {
                node->next[c - 'a'] = new Trie();
            }
            node = node->next[c - 'a'];
            node->count_start_with++;
        }
        node->count_is_end++;
    }

    int countWordsEqualTo(string word) {
        auto node = this;
        for (char c: word) {
            if (!node->next[c - 'a']) return 0;
            node = node->next[c - 'a'];
        }
        return node->count_is_end;
    }

    int countWordsStartingWith(string prefix) {
        auto node = this;
        for (char c: prefix) {
            if (!node->next[c - 'a']) return 0;
            node = node->next[c - 'a'];
        }
        return node->count_start_with;
    }

    void erase(string word) {
        auto node = this;
        for (char c: word) {
            node = node->next[c - 'a'];
            node->count_start_with--;
        }
        node->count_is_end--;
    }
};