#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries) {
        auto is_vowel = [&](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        int n = (int) words.size();
        int s[n + 1];
        s[0] = 0;
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + (is_vowel(words[i - 1].front()) && is_vowel(words[i - 1].back()));
        }
        vector<int> res;
        res.reserve(queries.size());
        for (auto &q: queries) {
            res.push_back(s[q[1] + 1] - s[q[0]]);
        }
        return res;
    }
};