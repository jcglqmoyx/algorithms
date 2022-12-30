#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string sortString(string s) {
        string res;
        int count[26] = {};
        for (char c: s) {
            count[c - 'a']++;
        }
        while (res.size() != s.size()) {
            for (int i = 0; i < 26; i++) {
                if (count[i]) {
                    res += i + 'a';
                    count[i]--;
                }
            }
            for (int i = 25; i >= 0; i--) {
                if (count[i]) {
                    res += i + 'a';
                    count[i]--;
                }
            }
        }
        return res;
    }
};