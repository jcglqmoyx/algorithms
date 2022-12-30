#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int cnt[26] = {0};
        for (char c: word1) cnt[c - 'a']++;
        for (char c: word2) cnt[c - 'a']--;
        return all_of(cnt, cnt + 26, [](int x) {
            return abs(x) <= 3;
        });
    }
};