#include <bits/stdc++.h>

using namespace std;

class Solution {
    int n;
    vector<string> abbreviations;

    void backtrack(string &word, string &cur, int i, int count) {
        int len = (int) cur.size();
        if (i == n) {
            if (count) {
                cur += to_string(count);
            }
            abbreviations.push_back(cur);
        } else {
            backtrack(word, cur, i + 1, count + 1);
            if (count) cur += to_string(count);
            cur.push_back(word[i]);
            backtrack(word, cur, i + 1, 0);
        }
        cur = cur.substr(0, len);
    }

public:
    vector<string> generateAbbreviations(string word) {
        n = (int) word.size();
        string cur;
        backtrack(word, cur, 0, 0);
        return abbreviations;
    }
};