#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        unordered_set<string> st, word_set(wordList.begin(), wordList.end());
        int step = 0;
        queue<string> q;
        q.push(beginWord);
        while (!q.empty()) {
            step++;
            for (auto it = q.size(); it; it--) {
                auto t = q.front();
                q.pop();
                if (t == endWord) return step;
                for (int i = 0; i < beginWord.size(); i++) {
                    string s = t;
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == t[i]) continue;
                        s[i] = c;
                        if (word_set.count(s) && !st.count(s)) {
                            q.push(s);
                            st.insert(s);
                        }
                    }
                }
            }
        }
        return 0;
    }
};