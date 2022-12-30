#include <bits/stdc++.h>

using namespace std;

class Solution {
    struct Trie {
        bool is_end;
        Trie *ne[26];

        Trie() : is_end(false), ne() {}

        void insert(string &s) {
            auto trie = this;
            for (char c: s) {
                int idx = c - 'a';
                if (!trie->ne[idx]) trie->ne[idx] = new Trie();
                trie = trie->ne[idx];
            }
            trie->is_end = true;
        }
    };

public:
    string longestCommonPrefix(vector<string> &strs) {
        auto trie = new Trie();
        for (auto &s: strs) trie->insert(s);
        string res;
        while (true) {
            int cnt = 0;
            bool flag = false;
            char c;
            for (int i = 0; i < 26; i++) {
                if (trie->ne[i]) cnt++, c = (char) (i + 'a');
                if (trie->is_end) flag = true;
            }
            if (flag) break;
            if (cnt == 1) res.push_back(c);
            else break;
            trie = trie->ne[c - 'a'];
        }
        return res;
    }
};