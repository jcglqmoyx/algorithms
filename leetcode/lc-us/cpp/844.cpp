#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string ss, tt;
        for (char c: s) {
            if (c != '#') {
                ss.push_back(c);
            } else if (!ss.empty()) {
                ss.pop_back();
            }
        }
        for (char c: t) {
            if (c != '#') {
                tt.push_back(c);
            } else if (!tt.empty()) {
                tt.pop_back();
            }
        }
        return ss == tt;
    }
};