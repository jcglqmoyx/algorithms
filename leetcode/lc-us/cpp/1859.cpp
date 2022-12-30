#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;
        while (ss >> word) {
            words.push_back(word);
        }
        sort(words.begin(), words.end(), [](string &a, string &b) {
            return a.back() < b.back();
        });
        string res;
        for (string &w: words) {
            res += w.substr(0, w.length() - 1) + ' ';
        }
        res.pop_back();
        return res;
    }
};