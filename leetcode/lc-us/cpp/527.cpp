#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> wordsAbbreviation(vector<string> &words) {
        int n = (int) words.size();
        unordered_map<string, vector<int>> map;
        vector<string> res(n);
        for (int i = 0; i < n; i++) {
            if (words[i].length() <= 3) res[i] = words[i];
            else map[get_abbr(words[i])].push_back(i);
        }

        function<int(Trie * , string & s)> get = [&](Trie *trie, string &s) -> int {
            int res = 1;
            for (char c: s) {
                if (trie->ne[c - 'a']->cnt > 1) {
                    trie = trie->ne[c - 'a'];
                } else {
                    break;
                }
                res++;
            }
            return res;
        };

        for (auto &[k, v]: map) {
            auto trie = new Trie();
            for (int idx: v) {
                auto node = trie;
                for (char c: words[idx]) {
                    if (!node->ne[c - 'a']) {
                        node->ne[c - 'a'] = new Trie();
                    }
                    node = node->ne[c - 'a'];
                    node->cnt++;
                }
            }
            int m = (int) words[v[0]].size();
            for (int idx: v) {
                int mx = get(trie, words[idx]);
                if (mx >= m - 2) res[idx] = words[idx];
                else {
                    auto t = words[idx].substr(0, mx);
                    res[idx] = t + to_string(m - mx - 1);
                    res[idx].push_back(words[idx].back());
                }
            }
        }
        return res;
    }

private:
    class Trie {
    public:
        int cnt;
        Trie *ne[26];

        Trie() : cnt(0), ne() {}

        ~Trie() {
            for (auto &child: ne) delete child;
        }
    };

    string get_abbr(string &s) {
        string res;
        res.push_back(s.front());
        res += to_string(s.size() - 2);
        res.push_back(s.back());
        return res;
    }
};