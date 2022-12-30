#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string> &words) {
        unordered_map<string, int> cnt1;
        int cnt2[26] = {};
        int res = 0;
        for (auto &s: words) {
            if (s[0] != s[1]) {
                cnt1[s]++;
            } else {
                cnt2[s[0] - 'a']++;
            }
        }
        for (auto &s: words) {
            if (cnt1[s]) {
                string t;
                t.push_back(s[1]);
                t.push_back(s[0]);
                if (cnt1.count(t)) {
                    int mn = min(cnt1[s], cnt1[t]);
                    cnt1[s] -= mn, cnt1[t] -= mn;
                    res += mn << 2;
                }
            }
        }
        int mx = 0, idx;
        for (int i = 0; i < 26; i++) {
            if (cnt2[i] & 1) {
                if (cnt2[i] > mx) {
                    mx = cnt2[i];
                    idx = i;
                }
            } else {
                res += cnt2[i] << 1;
            }
        }
        res += mx << 1;
        for (int i = 0; i < 26; i++) {
            if (i == idx) continue;
            if (cnt2[i] & 1) res += (cnt2[i] - 1) << 1;
        }
        return res;
    }
};