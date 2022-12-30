#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<string> get(string s) {
        vector<string> res;
        if (s.size() == 1 || s[0] != '0') res.push_back(s);
        for (int i = 1; i < s.size(); i++) {
            string l = s.substr(0, i);
            if (l.size() > 1 && l[0] == '0') continue;
            string r = s.substr(i);
            if (r.back() == '0') continue;
            res.push_back(l + '.' + r);
        }
        return res;
    }

public:
    vector<string> ambiguousCoordinates(string s) {
        vector<string> res;
        s = s.substr(1, s.size() - 2);
        for (int len = 1; len <= s.size() - 1; len++) {
            auto left = get(s.substr(0, len)), right = get(s.substr(len));
            for (auto &l: left) {
                for (auto &r: right) {
                    string coordinate;
                    coordinate.append("(");
                    coordinate.append(l);
                    coordinate.append(", ");
                    coordinate.append(r);
                    coordinate.append(")");
                    res.push_back(coordinate);
                }
            }
        }
        return res;
    }
};