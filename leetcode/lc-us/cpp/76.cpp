#include  <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int hs[128] = {0}, ht[128] = {0};
        for (char c: t) ht[c]++;
        int cnt = 0;
        string res;
        for (int i = 0, j = 0; j < s.length(); j++) {
            hs[s[j]]++;
            if (hs[s[j]] <= ht[s[j]]) cnt++;
            while (hs[s[i]] > ht[s[i]]) hs[s[i++]]--;
            if (cnt == t.length() && (res.empty() || j - i + 1 < res.length())) {
                res = s.substr(i, j - i + 1);
            }
        }
        return res;
    }
};