#include <bits/stdc++.h>

using namespace std;

class Solution {
    bool check(string &s, string &t) {
        int n = s.size(), m = t.size();
        if (n - m != 2) return false;
        return s.find(t) != -1;
    }

public:
    bool makeEqual(vector<string> &words) {
        int n = words.size();
        int cnt[26] = {0};
        for (auto &w: words) {
            for (char c: w) {
                cnt[c - 'a']++;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % n) return false;
        }
        return true;

    }
};