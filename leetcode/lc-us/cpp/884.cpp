#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> uncommon_words;
        vector<string> a = get_words(A), b = get_words(B);
        unordered_map<string, int> map;
        for (const string &word: a) {
            map[word]++;
        }
        for (const string &word: b) {
            map[word]++;
        }
        for (const auto &x: map) {
            if (map[x.first] == 1) {
                uncommon_words.push_back(x.first);
            }
        }
        return uncommon_words;
    }

private:
    vector<string> get_words(const string &sentence) {
        vector<string> set;
        int start = 0;
        for (int i = 0; i < sentence.length(); i++) {
            if (sentence[i] == ' ') {
                set.push_back(sentence.substr(start, i - start));
                start = i + 1;
            } else if (i == sentence.length() - 1) {
                set.push_back(sentence.substr(start, i - start + 1));
            }
        }
        return set;
    }
};