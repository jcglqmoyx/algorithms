#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        unordered_set<string> word_set(wordList.begin(), wordList.end());
        unordered_map<string, int> dist;
        dist[beginWord] = 1;
        queue<string> q;
        q.push(beginWord);
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            string s = t;
            for (int i = 0; i < t.length(); i++) {
                t = s;
                for (char c = 'a'; c <= 'z'; c++) {
                    t[i] = c;
                    if (word_set.count(t) && !dist.count(t)) {
                        dist[t] = dist[s] + 1;
                        if (t == endWord) return dist[t];
                        q.push(t);
                    }
                }
            }
        }
        return 0;
    }
};