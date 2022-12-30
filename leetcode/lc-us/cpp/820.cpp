#include <bits/stdc++.h>

using namespace std;

struct Trie {
    int cnt;
    Trie *next[26];

    Trie() : cnt(0), next() {}

    void insert(string &s) {
        int n = (int) s.size();
        auto root = this;
        for (int i = n - 1; ~i; i--) {
            if (!root->next[s[i] - 'a']) {
                root->next[s[i] - 'a'] = new Trie();
            }
            root = root->next[s[i] - 'a'];
            root->cnt++;
        }
    }

    bool query(string &s) {
        int n = (int) s.size();
        auto root = this;
        for (int i = n - 1; ~i; i--) {
            root = root->next[s[i] - 'a'];
        }
        return all_of(root->next, root->next + 26, [](Trie *trie) {
            return !trie;
        });
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string> &words) {
        Trie *trie = new Trie();
        unordered_set<string> word_set;
        for (string &w: words) {
            trie->insert(w);
            word_set.insert(w);
        }
        int res = 0;
        for (string w: word_set) {
            if (trie->query(w)) {
                res += (int) w.length() + 1;
            }
        }
        return res;
    }
};