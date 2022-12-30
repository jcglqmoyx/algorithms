#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSubstrings(string s, string t) {
        int n = (int) s.size(), m = (int) t.size(), res = 0;
        for (int delta = 1 - n; delta < m; delta++) {
            int i = 0, j = 0;
            if (delta < 0) i = -delta;
            else j = delta;
            int fij = 0, gij = 0;
            for (; i < n && j < m; i++, j++) {
                if (s[i] == t[j]) gij++;
                else fij = gij + 1, gij = 0;
                res += fij;
            }
        }
        return res;
    }
};