#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> removeAnagrams(vector<string> &words) {
        vector<string> res;
        vector<int> cnt(26);
        for (auto &word: words) {
            vector<int> t(26);
            for (char c: word) t[c - 'a']++;
            bool flag = true;
            for (int j = 0; j < 26; j++) {
                if (cnt[j] != t[j]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) res.push_back(word), cnt = t;
        }
        return res;
    }
};