#include <bits/stdc++.h>

using namespace std;

class Solution {
    static bool cmp(const string &word1, const string &word2) {
        return word1.length() < word2.length();
    }

public:
    vector<string> stringMatching(vector<string> &words) {
        vector<string> res;
        sort(words.begin(), words.end(), cmp);
        for (int i = 0; i < words.size() - 1; i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (words[j].find(words[i]) != string::npos) {
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};