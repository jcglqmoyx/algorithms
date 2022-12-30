#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> words;
        int max_len = 0;
        for (int i = 0, j = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                words.push_back(s.substr(j, i - j));
                max_len = max(max_len, i - j);
                j = i + 1;
            }
            if (i == s.size() - 1) {
                words.push_back(s.substr(j, i - j + 1));
                max_len = max(max_len, i - j + 1);
            }
        }
        vector<string> res;
        for (int i = 0; i < max_len; i++) {
            string word;
            for (auto &w: words) {
                char c = i >= w.size() ? ' ' : w[i];
                word.push_back(c);
            }
            while (word.back() == ' ') word.pop_back();
            res.push_back(word);
        }
        return res;
    }
};