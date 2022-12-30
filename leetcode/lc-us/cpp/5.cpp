#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string t = "^#";
        for (char c: s) {
            t.push_back(c);
            t.push_back('#');
        }
        t.push_back('$');
        int n = (int) t.size();
        vector<int> p(n + 1);
        int mr = 0, mid;
        for (int i = 1; i < n; i++) {
            if (i < mr) p[i] = min(p[(mid << 1) - i], mr - i);
            else p[i] = 1;
            while (t[i - p[i]] == t[i + p[i]]) p[i]++;
            if (i + p[i] > mr) {
                mr = i + p[i];
                mid = i;
            }
        }
        int mx = 0, idx;
        for (int i = 1; i < n; i++) {
            if (p[i] > mx) {
                mx = p[i];
                idx = i;
            }
        }
        return s.substr((idx - mx) >> 1, mx - 1);
    }
};