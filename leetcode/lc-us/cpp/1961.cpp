#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPrefixString(string s, vector<string> &words) {
        string t;
        for (string &w: words) {
            t += w;
            if (t == s) return true;
        }
        return false;
    }
};