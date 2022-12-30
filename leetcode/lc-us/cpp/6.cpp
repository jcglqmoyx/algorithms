#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (s.length() <= numRows || numRows == 1) return s;
        vector<string> rows(numRows);
        bool downward = false;
        int cur = 0;
        for (char c: s) {
            if (cur == 0 || cur == numRows - 1) downward = !downward;
            rows[cur].push_back(c);
            cur += downward ? 1 : -1;
        }
        string res;
        for (const string &row: rows) res.append(row);
        return res;
    }
};