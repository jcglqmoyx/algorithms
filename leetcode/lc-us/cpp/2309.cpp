#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string greatestLetter(string s) {
        string res;
        unordered_set<char> S;
        for (char c: s) S.insert(c);
        for (char c: s) {
            char x = (char) tolower(c);
            char y = (char) toupper(c);
            if (S.count(x) && S.count(y)) {
                if (res.empty()) {
                    res.push_back(y);
                } else if (res.back() < y) {
                    res.back() = y;
                }
            }
        }
        return res;
    }
};