#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int> &spaces) {
        if (spaces.empty()) return s;
        string res;
        int idx = 0;
        for (int x: spaces) {
            res += s.substr(idx, x - idx) + ' ';
            idx = x;
        }
        res += s.substr(idx);
        return res;
    }
};