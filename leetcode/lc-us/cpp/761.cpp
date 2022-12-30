#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string makeLargestSpecial(string s) {
        if (s.size() <= 2) return s;
        vector<string> q;
        int cnt = 0;
        string str;
        for (char c: s) {
            str.push_back(c);
            if (c == '1') {
                cnt++;
            } else {
                cnt--;
                if (cnt == 0) {
                    q.push_back('1' + makeLargestSpecial(str.substr(1, str.size() - 2)) + '0');
                    str.clear();
                }
            }
        }
        sort(q.begin(), q.end(), [&](const string &a, string const &b) {
            return a + b > b + a;
        });
        string res;
        for (auto &e: q) {
            res += e;
        }
        return res;
    }
};