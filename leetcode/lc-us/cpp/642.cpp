#include <bits/stdc++.h>

using namespace std;

using PSI = pair<string, int>;

int get_index(char c) {
    if (isalpha(c)) return c - 'a' + 1;
    else return 0;
}

char get_char(int idx) {
    if (idx) return (char) (idx - 1 + 'a');
    return ' ';
}

class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string> &sentences, vector<int> &times) {
        this->trie = new Trie(), this->cur = trie;
        this->flag = false;
        for (int i = 0; i < sentences.size(); i++) {
            trie->insert(sentences[i], times[i]);
        }
    }

    vector<string> input(char c) {
        if (c == '#') {
            trie->insert(s, 1);
            cur = trie;
            s.clear();
            this->flag = false;
            return {};
        } else {
            s.push_back(c);
            if (flag) return {};
            vector<PSI> v;
            int idx = get_index(c);
            if (!cur->next[idx]) {
                this->flag = true;
                return {};
            }
            cur = cur->next[idx];
            query(v, cur);
            sort(v.begin(), v.end(), [](const PSI &a, const PSI &b) {
                if (a.second == b.second) return a.first < b.first;
                return a.second > b.second;
            });
            vector<string> res;
            for (int i = 0; i < min(3, (int) v.size()); i++) {
                res.push_back(v[i].first);
            }
            return res;
        }
    }

private:
    class Trie {
    public:
        int cnt;
        Trie *next[27];

        Trie() : cnt(0), next() {}

        void insert(string &sentence, int freq) {
            auto node = this;
            for (char c: sentence) {
                int idx = get_index(c);
                if (!node->next[idx]) {
                    node->next[idx] = new Trie();
                }
                node = node->next[idx];
            }
            node->cnt += freq;
        }
    };

    Trie *trie;
    Trie *cur;
    string s;
    bool flag;

    void query(vector<PSI> &v, Trie *node) {
        if (node->cnt) v.emplace_back(s, node->cnt);
        for (int i = 0; i < 27; i++) {
            if (node->next[i]) {
                s.push_back(get_char(i));
                query(v, node->next[i]);
                s.pop_back();
            }
        }
    }
};