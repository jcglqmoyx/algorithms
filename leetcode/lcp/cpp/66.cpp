#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minNumBooths(vector<string> &demand) {
        int cnt[26] = {};
        for (auto &s: demand) {
            int t[26] = {};
            for (char c: s) {
                t[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                cnt[i] = max(cnt[i], t[i]);
            }
        }
        int res = 0;
        for (int i: cnt) {
            res += i;
        }
        return res;
    }
};