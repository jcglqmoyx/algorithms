#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string lastSubstring(string s) {
        int n = (int) s.size(), pos = n - 1;
        char mx = s[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] >= mx) pos = i, mx = s[i];
        }
        int r = pos + 1, j, k;
        while (r < n) {
            if (s[r] != mx) {
                r++;
            } else {
                j = pos + 1, k = r + 1;
                while (j < r && k < n) {
                    if (s[j] == s[k]) j++, k++;
                    else {
                        if (s[j] < s[k]) {
                            pos = r;
                            r = pos + 1;
                        } else r = k + 1;
                        break;
                    }
                }
                if (j == r || k == n) r = k;
            }
        }
        return s.substr(pos);
    }
};