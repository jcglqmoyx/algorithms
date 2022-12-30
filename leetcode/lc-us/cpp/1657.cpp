#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int m = (int) word1.size(), n = (int) word2.size();
        if (m != n) return false;
        unordered_set<char> s1, s2;
        int cnt1[26] = {0}, cnt2[26] = {0};
        for (int i = 0; i < n; ++i) {
            s1.insert(word1[i]);
            s2.insert(word2[i]);
            cnt1[word1[i] - 'a']++;
            cnt2[word2[i] - 'a']++;
        }
        for (char c: s1) {
            if (s2.find(c) == s2.end()) {
                return false;
            }
        }
        sort(cnt1, cnt1 + 26);
        sort(cnt2, cnt2 + 26);
        for (int i = 0; i < 26; i++) {
            if (cnt1[i] != cnt2[i]) {
                return false;
            }
        }
        return true;
    }
};