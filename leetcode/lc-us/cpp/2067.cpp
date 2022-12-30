#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int equalCountSubstrings(string s, int count) {
        int n = (int) s.size();
        int cnt[n + 1][26];
        memset(cnt, 0, sizeof cnt);
        for (int i = 1; i <= n; i++) {
            for (int c = 'a'; c <= 'z'; c++) {
                cnt[i][c - 'a'] = cnt[i - 1][c - 'a'];
            }
            cnt[i][s[i - 1] - 'a']++;
        }
        int res = 0;
        for (int len = count; len <= min(count * 26, n); len += count) {
            for (int i = 1; i + len - 1 <= n; i++) {
                int j = i + len - 1;
                bool valid = true;
                for (int k = 0; k < 26; k++) {
                    int diff = cnt[j][k] - cnt[i - 1][k];
                    if (diff && diff != count) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    res++;
                }
            }
        }
        return res;
    }
};