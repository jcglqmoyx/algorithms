#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        string res;
        for (char c: s) {
            res.push_back(c);
            if (res.size() >= part.size() && res.substr((int) res.size() - part.size(), part.size()) == part)
                res = res.substr(0, res.size() - part.size());
        }
        return res;
    }
};