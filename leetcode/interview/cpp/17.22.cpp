#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<string> res;
    unordered_set<string> word_set;
    unordered_set<string> vis;

    void dfs(string &target, string &start, vector<string> &words, vector<string> &path) {
        if (start == target) {
            res = path;
            return;
        }
        for (int i = 0; i < start.length(); i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                string s = start.substr(0, i) + c + start.substr(i + 1);
                if (word_set.count(s) && !vis.count(s)) {
                    vis.insert(s);
                    path.push_back(s);
                    dfs(target, s, words, path);
                    path.pop_back();
                }
            }
        }
    }

public:
    vector<string> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        for (string &word: wordList) word_set.insert(word);
        vis.insert(beginWord);
        vector<string> path = {beginWord};
        dfs(endWord, beginWord, wordList, path);
        return res;
    }
};