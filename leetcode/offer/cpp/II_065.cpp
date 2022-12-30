#include <bits/stdc++.h>

using namespace std;

struct Trie {
    int len;
    int sum;
    Trie *ne[26];

    Trie() : len(0), sum(0), ne() {}

    void insert(string &s) {
        auto t = this;
        for (char c: s) {
            int j = c - 'a';
            if (!t->ne[j]) t->ne[j] = new Trie();
            else if (t->ne[j]->len) {
                this->sum -= t->ne[j]->len + 1;
                t->ne[j]->len = 0;
            }
            t = t->ne[j];
        }
        t->len = (int) s.size();
        this->sum += t->len + 1;
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string> &words) {
        sort(words.begin(), words.end(), [&](string &a, string &b) {
            return a.size() < b.size();
        });
        auto t = new Trie;
        for (auto &word: words) {
            reverse(word.begin(), word.end());
            t->insert(word);
        }
        return t->sum;
    }
};