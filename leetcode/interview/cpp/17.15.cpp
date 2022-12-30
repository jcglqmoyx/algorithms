#include <bits/stdc++.h>

using namespace std;

struct Trie {
    bool is_end;
    Trie *next[26];

    Trie() : is_end(false), next() {}

    void insert(string &w) {
        Trie *root = this;
        for (char c: w) {
            if (!root->next[c - 'a']) root->next[c - 'a'] = new Trie();
            root = root->next[c - 'a'];
        }
        root->is_end = true;
    }

    bool exits(string &w) {
        Trie *root = this;
        for (char c: w) {
            if (!root->next[c - 'a']) return false;
            root = root->next[c - 'a'];
        }
        return root->is_end;
    }
};

class Solution {
public:
    string longestWord(vector<string> &words) {
        auto *trie = new Trie();
        for (string &w: words) trie->insert(w);
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            if (a.length() == b.length()) return a < b;
            else return a.length() > b.length();
        });
        for (string &w: words) {
            if (search(trie, w, 0, 0)) {
                return w;
            }
        }
        return "";
    }

private:
    bool search(Trie *root, string &w, int prev, int cur) {
        if (prev == w.length()) return true;
        string s = w.substr(prev, cur - prev + 1);
        if (s == w) return false;
        if (root->exits(s)) {
            if (search(root, w, cur + 1, cur + 1)) {
                return true;
            }
            if (search(root, w, prev, cur + 1)) {
                return true;
            }
        } else {
            if (cur < w.length() - 1 && search(root, w, prev, cur + 1)) {
                return true;
            }
        }
        return false;
    }
};