#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = (int) s.size();
        int f[n], pos[26];
        memset(f, 0, sizeof f), memset(pos, -1, sizeof pos);
        int res = 0;
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            f[i] = 1;
            for (int j = idx; idx - j <= k && ~j; j--) {
                if (pos[j] != -1) {
                    f[i] = max(f[i], f[pos[j]] + 1);
                }
            }
            for (int j = idx + 1; j < min(26, idx + k + 1); j++) {
                if (pos[j] != -1) {
                    f[i] = max(f[i], f[pos[j]] + 1);
                }
            }
            pos[idx] = i;
            res = max(res, f[i]);
        }
        return res;
    }
};