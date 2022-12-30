#include <bits/stdc++.h>

using namespace std;

class Solution {
    int trie[100005][30];
    int num[100005];
    int count[100005];
    int cnt = 0;
    int maxLen = 0;
    map<int, vector<string>> m;
    pair<int, vector<string>> ans = {0, {}};

    void add(string &s) {
        int root = 0;
        for (int i = 0; i < s.length(); i++) {
            char cur = s[i] - 'a';
            if (!trie[root][cur]) {
                trie[root][cur] = ++cnt;
            }
            root = trie[root][cur];
            num[root]++;
        }
        count[root]++;
    }

    int judge(vector<string> &cur) {
        int height = (int) cur.size();
        int width = (int) cur[0].size();
        bool canGo = true;
        for (int i = 0; i < width; i++) {
            int root = 0;
            for (int j = 0; j < height; j++) {
                char now = cur[j][i];
                if (!trie[root][now - 'a'])
                    return 0;
                root = trie[root][now - 'a'];
            }
            if (!count[root])
                canGo = false;
        }
        if (!canGo) return 1;
        return 2;
    }

    void dfs(vector<string> &cur, vector<string> &all) {
        if (all[0].length() * maxLen <= ans.first)
            return;
        for (const auto &word: all) {
            cur.emplace_back(word);
            int get = judge(cur);
            if (get == 1) {
                dfs(cur, all);
            } else if (get == 2) {
                if (ans.first < cur.size() * cur[0].length()) {
                    ans.second.clear();
                    for (auto &i: cur) ans.second.emplace_back(i);
                    ans.first = cur.size() * cur[0].length();
                }
                dfs(cur, all);
            }
            cur.pop_back();
        }
    }

public:
    vector<string> maxRectangle(vector<string> &words) {
        for (auto word: words) add(word);
        for (const auto &word: words) m[word.length()].emplace_back(word);
        maxLen = (*m.rbegin()).first;
        vector<string> cur;
        for (auto mm: m) {
            dfs(cur, mm.second);
        }
        return ans.second;
    }
};