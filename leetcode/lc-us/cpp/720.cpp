#include <bits/stdc++.h>

using namespace std;

class Solution {
    static bool cmp(const string &a, const string &b) {
        if (a.length() != b.length()) {
            return a.length() < b.length();
        } else {
            return a > b;
        }
    }

public:
    string longestWord(vector<string> &words) {
        unordered_set<string> word_set;
        for (const string &word: words) {
            word_set.insert(word);
        }
        sort(words.begin(), words.end(), &cmp);
        for (int i = (int) words.size() - 1; i >= 0; i--) {
            bool flag = true;
            for (int len = 1; len < words[i].length(); len++) {
                if (!word_set.count(words[i].substr(0, len))) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return words[i];
            }
        }
        return "";
    }
};