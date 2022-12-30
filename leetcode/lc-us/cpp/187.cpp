#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length() < 10) return {};
        unordered_set<string> sequences, repeated_sequences;
        for (int i = 0; i <= s.length() - 10; i++) {
            string word = s.substr(i, 10);
            if (sequences.count(word) && !repeated_sequences.count(word)) {
                repeated_sequences.insert(word);
            }
            sequences.insert(word);
        }
        vector<string> res;
        res.reserve(repeated_sequences.size());
        for (const string &word : repeated_sequences) res.push_back(word);
        return res;
    }
};