#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        int n = (int) s.size();
        if (n < 4 || n > 12) return res;
        for (int i = 1; i <= 3; i++) {
            for (int j = i + 1; j <= min(i + 3, n); j++) {
                for (int k = j + 1; k <= min(j + 3, n); k++) {
                    string a = s.substr(0, i), b = s.substr(i, j - i), c = s.substr(j, k - j), d = s.substr(k);
                    if (valid(a) && valid(b) && valid(c) && valid(d)) {
                        res.push_back(a + '.' + b + '.' + c + '.' + d);
                    }
                }
            }
        }
        return res;
    }

private:
    bool valid(string &s) {
        if (s.size() > 3 || s.empty()) return false;
        if (s.size() > 1 && s[0] == '0') return false;
        int x = stoi(s);
        return x >= 0 && x <= 255;
    }
};