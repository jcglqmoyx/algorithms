#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true;
        int m = -1, n = -1;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                if (m != -1 && n != -1) return false;
                else if (m == -1) m = i;
                else if (n == -1) n = i;
            }
        }
        if (m >= 0 && n >= 0) swap(s2[m], s2[n]);
        return s1 == s2;
    }
};