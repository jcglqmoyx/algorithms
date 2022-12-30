#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<string> path;
    vector<vector<string>> paths;
    unordered_set<string> set;

    void dfs(string &s, int prev, int index) {
        int n = (int) s.size();
        if (prev == n) {
            paths.push_back(path);
            return;
        }
        for (int i = index; i < n; i++) {
            string word = s.substr(prev, i - prev + 1);
            if (set.count(word)) {
                path.push_back(word);
                dfs(s, i + 1, i + 1);
                path.pop_back();
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        for (string &w: wordDict) set.insert(w);
        dfs(s, 0, 0);
        vector<string> res;
        for (auto &p: paths) {
            string sentence;
            for (string &word: p) {
                sentence += word + ' ';
            }
            sentence.pop_back();
            res.push_back(sentence);
        }
        return res;
    }
};