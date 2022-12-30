#include <bits/stdc++.h>

using namespace std;

class Trie {
public:
    bool is_end;
    Trie *next[26];

    Trie() {
        is_end = false;
        memset(next, 0, sizeof(next));
    }
};

class MagicDictionary {
    Trie *root;

    bool find(string &word, int index, bool used, Trie *node) {
        if (index == word.size())
            return node->is_end && used;
        if (!node->next[word[index] - 'a']) {
            if (used)
                return false;
            else {
                for (int i = 0; i < 26; i++) {
                    if (node->next[i] && find(word, index + 1, true, node->next[i]))
                        return true;
                }
                return false;
            }
        } else {
            if (find(word, index + 1, used, node->next[word[index] - 'a']))
                return true;
            if (!used) {
                for (int i = 0; i < 26; i++) {
                    if (i != word[index] - 'a' && node->next[i] && find(word, index + 1, true, node->next[i]))
                        return true;
                }
                return false;
            }
        }
        return false;
    }

public:
    MagicDictionary() {
        root = new Trie();
    }

    void buildDict(vector<string> dictionary) {
        for (auto &w: dictionary) {
            Trie *node = root;
            for (auto &c: w) {
                if (!node->next[c - 'a'])
                    node->next[c - 'a'] = new Trie();
                node = node->next[c - 'a'];
            }
            node->is_end = true;
        }
    }

    bool search(string searchWord) {
        return find(searchWord, 0, false, root);
    }
};