#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        string res;
        if (s.size() < t.size()) return res;
        int cnt_s[123] = {}, cnt_t[123] = {};
        for (char c: t) cnt_t[c]++;
        for (int i = 0, j = 0; j < s.size(); j++) {
            cnt_s[s[j]]++;
            bool flag = true;
            for (int k = 0; k < 123; k++) {
                if (cnt_t[k] > cnt_s[k]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                while (cnt_s[s[i]] > cnt_t[s[i]]) cnt_s[s[i]]--, i++;
                if (res.empty() || res.size() > j - i + 1) res = s.substr(i, j - i + 1);
            }
        }
        return res;
    }
};