#include <bits/stdc++.h>

using namespace std;

class MagicDictionary {
public:
    MagicDictionary() {
        trie = new Trie();
    }

    void buildDict(vector<string> dictionary) {
        for (auto &word: dictionary) trie->insert(word);
    }

    bool search(string searchWord) {
        return trie->search(trie, searchWord);
    }

private:
    struct Trie {
        bool is_end;
        Trie *next[26];

        Trie() : is_end(false), next() {}

        void insert(string &s) {
            Trie *root = this;
            for (char c: s) {
                if (!root->next[c - 'a']) root->next[c - 'a'] = new Trie();
                root = root->next[c - 'a'];
            }
            root->is_end = true;
        }

        bool search(Trie *root, string &s) {
            for (int i = 0; i < s.size(); i++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == s[i]) continue;
                    if (root->next[c - 'a']) {
                        if (exists(root->next[c - 'a'], s, i + 1)) {
                            return true;
                        }
                    }
                }
                if (root->next[s[i] - 'a']) root = root->next[s[i] - 'a'];
                else break;
            }
            return false;
        }

        bool exists(Trie *root, string &s, int index) {
            for (int i = index; i < s.size(); i++) {
                if (!root->next[s[i] - 'a']) return false;
                root = root->next[s[i] - 'a'];
            }
            return root->is_end;
        }
    };

    Trie *trie;
};