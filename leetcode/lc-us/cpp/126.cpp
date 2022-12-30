#include <bits/stdc++.h>

using namespace std;

class Solution {
    unordered_set<string> word_set;
    unordered_map<string, int> dist;
    int len;
    string begin_word;
    vector<string> path;
    vector<vector<string>> paths;

    void dfs(string s) {
        if (s == begin_word) {
            reverse(path.begin(), path.end());
            paths.push_back(path);
            reverse(path.begin(), path.end());
        } else {
            string tmp = s;
            for (int i = 0; i < len; i++) {
                s = tmp;
                for (char c = 'a'; c <= 'z'; c++) {
                    s[i] = c;
                    if (dist.count(s) && dist[s] + 1 == dist[tmp]) {
                        path.push_back(s);
                        dfs(s);
                        path.pop_back();
                    }
                }
            }
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        len = (int) beginWord.length();
        begin_word = beginWord;
        dist[beginWord] = 0;
        for (const auto &w: wordList) word_set.insert(w);
        queue<string> q;
        q.push(beginWord);
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            auto tmp = t;
            for (int i = 0; i < len; i++) {
                t = tmp;
                for (char c = 'a'; c <= 'z'; c++) {
                    t[i] = c;
                    if (word_set.count(t) && !dist.count(t)) {
                        dist[t] = dist[tmp] + 1;
                        if (t == endWord) break;
                        q.push(t);
                    }
                }
            }
        }
        if (dist.count(endWord) == 0) return paths;
        path.push_back(endWord);
        dfs(endWord);
        return paths;
    }
};