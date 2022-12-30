#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = (int) s.size();
        int cnt[3] = {};
        for (char c: s) {
            cnt[c - 'a']++;
        }
        for (int i: cnt) {
            if (i < k) return -1;
        }
        int res = n + 1;
        for (int r = 0, l = 0; r < n; r++) {
            int idx = s[r] - 'a';
            cnt[idx]--;
            while (cnt[idx] < k) {
                cnt[s[l] - 'a']++;
                l++;
            }
            res = min(res, n - (r - l + 1));
        }
        return res > n ? -1 : res;
    }
};