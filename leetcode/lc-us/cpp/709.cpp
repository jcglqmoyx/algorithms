#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string toLowerCase(string s) {
        string res;
        for (char c: s) {
            res += tolower(c);
        }
        return res;
    }
};