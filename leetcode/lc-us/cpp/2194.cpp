#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> res;
        char c1, c2;
        int r1, r2;
        sscanf(s.c_str(), "%c%d:%c%d", &c1, &r1, &c2, &r2);
        for (char c = c1; c <= c2; c++) {
            for (int r = r1; r <= r2; r++) {
                string ss;
                ss.push_back(c);
                ss += to_string(r);
                res.push_back(ss);
            }
        }
        return res;
    }
};