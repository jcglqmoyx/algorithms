#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int balancedString(string s) {
        char chars[4] = {'Q', 'W', 'E', 'R'};
        int n = (int) s.size(), res = n;
        int map[123] = {0};
        for (char c: s) map[c]++;
        bool ok = true;
        for (char c: chars) {
            if (map[c] != (n >> 2)) {
                ok = false;
                break;
            }
        }
        if (ok) return 0;

        int cnt[123] = {0};
        for (int i = 0, j = 0; j < n; j++) {
            cnt[s[j]]++;
            while (i <= j) {
                bool valid = true;
                for (char c: chars) {
                    if (cnt[c] < map[c] - (n >> 2)) {
                        valid = false;
                        break;
                    }
                }
                if (valid) cnt[s[i]]--, res = min(res, j - i + 1), i++;
                else break;
            }
        }
        return res;
    }
};