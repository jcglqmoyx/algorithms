#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        bool f1 = false, f2 = false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') f1 = true;
            if (target[i] == '1') f2 = true;
        }
        return f1 == f2;
    }
};