#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        string str;
        int cnt[123] = {};
        for (char c: s) cnt[c]++;
        for (char c: s) {
            if (cnt[c] >= k) str.push_back(c);
        }
        string chars;
        for (char c = 'z'; c >= 'a'; c--) {
            if (cnt[c] >= k) {
                for (int i = 0; i < cnt[c] / k; i++) {
                    chars.push_back(c);
                }
            }
        }
        int n = (int) str.size(), m = (int) chars.size();
        if (!n) return "";

        int suf[n + 1][26];
        memset(suf, -1, sizeof suf);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 26; j++) {
                suf[i][j] = suf[i + 1][j];
            }
            suf[i][str[i] - 'a'] = i;
        }

        string res;

        bool st[m];
        memset(st, false, sizeof st);
        string t;

        function<bool(string)> valid = [&](string s) -> bool {
            int i = 0, j = 0;
            int K = k;
            while (K) {
                j = suf[j][s[i] - 'a'];
                if (j == -1) break;
                i++, j++;
                if (i == s.size()) i = 0, K--;
            }
            return !K;
        };

        function<void()> check = [&]() {
            for (int i = 1; i < 1 << m; i++) {
                int L = __builtin_popcount(i);
                if (L < res.size()) continue;
                else {
                    string temp;
                    for (int j = 0; j < m; j++) {
                        if (i >> j & 1) temp.push_back(t[j]);
                    }
                    if (L == res.size() && temp <= res) continue;
                    if (valid(temp)) {
                        res = temp;
                    }
                }
            }
        };

        function<void(int)> dfs = [&](int u) {
            if (u == m) {
                check();
                return;
            }
            for (int i = 0; i < m; i++) {
                if (!st[i]) {
                    st[i] = true;
                    t.push_back(chars[i]);
                    dfs(u + 1);
                    st[i] = false;
                    t.pop_back();
                }
            }
        };
        dfs(0);
        return res;
    }
};
