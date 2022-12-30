#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if (s.length() != t.length()) return false;
        int n = (int) s.size();
        int map[26] = {};
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                int diff = (t[i] - s[i] + 26) % 26;
                if (map[diff] == 0) map[diff] = diff;
                else map[diff] = map[diff] + 26;
                if (map[diff] > k) return false;
            }
        }
        return true;
    }
};