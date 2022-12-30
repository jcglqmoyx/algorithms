#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPrefixes(vector<string> &words, string s) {
        int cnt = 0;
        for (const auto &word: words) {
            int n = (int) word.size(), m = (int) s.size();
            if (n > m) continue;
            if (word == s.substr(0, n)) cnt++;
        }
        return cnt;
    }
};