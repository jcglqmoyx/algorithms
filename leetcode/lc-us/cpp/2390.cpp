#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeStars(string s) {
        int n = (int) s.size();
        string res;
        for (char c: s) {
            if (c != '*') {
                res.push_back(c);
            } else {
                res.pop_back();
            }
        }
        return res;
    }
};