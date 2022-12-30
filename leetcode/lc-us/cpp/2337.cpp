#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canChange(string s, string t) {
        int n = (int) s.size();
        for (int i = 0, j = 0; i < n && j < n;) {
            while (i < n && s[i] == '_') i++;
            while (j < n && t[j] == '_') j++;
            if (i < n && j < n) {
                if (s[i] != t[j] || s[i] == 'L' && t[j] == 'L' && i < j || s[i] == 'R' && t[j] == 'R' && i > j) {
                    return false;
                }
            } else if (i < n || j < n) {
                return false;
            }
            i++, j++;
        }
        int cnt1 = 0, cnt2 = 0;
        for (char c: s) {
            if (c == 'L') cnt1++;
            else if (c == 'R') cnt2++;
        }
        for (char c: t) {
            if (c == 'L') cnt1--;
            else if (c == 'R') cnt2--;
        }
        if (cnt1 || cnt2) return false;
        return true;
    }
};