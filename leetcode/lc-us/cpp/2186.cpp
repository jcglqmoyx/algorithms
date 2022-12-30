#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        int res = 0;
        int f[26] = {0}, g[26] = {};
        for (char c: s) f[c - 'a']++;
        for (char c: t) g[c - 'a']++;
        for (int i = 0; i < 26; i++) {
            int mn = min(f[i], g[i]);
            f[i] -= mn, g[i] -= mn;
        }
        for (int i = 0; i < 26; i++) {
            res += f[i] + g[i];
        }
        return res;
    }
};