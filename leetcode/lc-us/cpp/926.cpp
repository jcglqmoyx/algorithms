#include <bits/stdc++.h>

using namespace std;

/*
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = (int) s.size();
        vector<int> cnt(n + 1);
        for (int i = 1; i <= n; i++) {
            cnt[i] = cnt[i - 1] + (s[i - 1] == '1');
        }
        int res = min(cnt[n], n - cnt[n]);
        for (int i = 1; i <= n; i++) {
            res = min(res, cnt[i] + n - i - (cnt[n] - cnt[i]));
        }
        return res;
    }
};
 */

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int cnt1 = 0, min_diff = 0;
        for (char c: s) {
            if (c == '1') cnt1++;
            else if (cnt1 > min_diff) min_diff++;
        }
        return min_diff;
    }
};