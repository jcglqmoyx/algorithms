#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumScore(string s, string t) {
        int n = (int) s.size(), m = (int) t.size();
        int suf[n + 1];
        memset(suf, 0, sizeof suf);
        for (int i = n - 1, j = m - 1; i >= 0; i--) {
            suf[i] = suf[i + 1];
            if (j >= 0 && s[i] == t[j]) suf[i]++, j--;
        }
        int res = m - suf[0];
        for (int i = 0, j = 0, pre = 0; i < n; i++) {
            if (j < m - 1 && s[i] == t[j]) pre++, j++;
            res = min(res, max(0, m - (pre + suf[i + 1])));
        }
        return res;
    }
};