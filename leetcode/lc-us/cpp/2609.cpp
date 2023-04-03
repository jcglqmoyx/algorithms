#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int res = 0, len0 = 0, len1 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                len1++;
                res = max(res, min(len0, len1) * 2);
            } else {
                if (i && s[i - 1] == '1') len0 = 0;
                len0++, len1 = 0;
            }
        }
        return res;
    }
};