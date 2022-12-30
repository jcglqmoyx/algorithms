#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        if (s == t) return false;
        int cnt1[26] = {}, cnt2[26] = {};
        for (int i = 0; i < s.size(); i++) {
            cnt1[s[i] - 'a']++;
            cnt2[t[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (cnt1[i] != cnt2[i]) return false;
        }
        return true;
    }
};