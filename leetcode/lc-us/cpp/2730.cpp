#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int res = 1, n = (int) s.size();
        for (int i = 0, j = 0; j < n;) {
            int pairs = 0;
            while (j + 1 < n) {
                if (s[j] == s[j + 1]) pairs++;
                if (pairs > 1) break;
                j++;
            }
            res = max(res, j - i + 1);
            if (j == n - 1) break;
            while (pairs > 1) {
                i++;
                if (s[i] == s[i - 1]) pairs--;
            }
        }
        return res;
    }
};