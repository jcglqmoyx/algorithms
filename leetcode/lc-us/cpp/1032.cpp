/*
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
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 40010;

int son[N][26], p, idx;
bool st[N];
int max_len;
string cur;

void insert(string &s) {
    p = 0;
    for (int i = (int) s.size() - 1; i >= 0; i--) {
        int u = s[i] - 'a';
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    st[p] = true;
}

bool exists() {
    p = 0;
    for (int i = (int) cur.size() - 1; i >= 0 && i >= (int) cur.size() - max_len; i--) {
        int u = cur[i] - 'a';
        if (!son[p][u]) return false;
        p = son[p][u];
        if (st[p]) return true;
    }
    return false;
}

class StreamChecker {
public:
    StreamChecker(vector<string> &words) {
        memset(son, 0, sizeof son), idx = 0, memset(st, 0, sizeof st);
        max_len = 0;
        cur.clear();
        for (auto &s: words) {
            insert(s);
            max_len = max(max_len, (int) s.size());
        }
    }

    bool query(char letter) {
        cur.push_back(letter);
        return exists();
    }
};