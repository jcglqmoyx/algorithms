#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = (int) s.size();
        if (n < k) return false;
        int cnt[26] = {0};
        for (char c: s) cnt[c - 'a']++;
        int odd = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] & 1) odd++;
        }
        if (odd > k) return false;
        return true;
    }
};