#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string makeGood(string s) {
        string res;
        for (char c: s) {
            if (!res.empty() && tolower(res.back()) == tolower(c) && res.back() != c) {
                res.pop_back();
            } else {
                res.push_back(c);
            }
        }
        return res;
    }
};