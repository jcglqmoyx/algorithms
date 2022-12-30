#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string res;
        for (char c: s)
            if (c == ' ') res += "%20";
            else res += c;
        return res;
    }
};