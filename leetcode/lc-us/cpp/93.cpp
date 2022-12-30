#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        int n = (int)s.size();
        if (n < 4 || n > 12) return res;
        for (int i = 1; i < 4; i++) {
            int one = stoi(s.substr(0, i));
            if (one > 255 || one != 0 && s[0] == '0' || one == 0 && i > 1) continue;
            for (int j = 1; j < 4; j++) {
                int two = stoi(s.substr(i, j));
                if (two > 255 || two != 0 && s[i] == '0' || two == 0 && j > 1) continue;
                for (int k = 1; k < 4; k++) {
                    if (i + j + k >= n) continue;
                    int three = stoi(s.substr(i + j, k));
                    if (three > 255 || three != 0 && s[i + j] == '0' || three == 0 && k > 1) continue;
                    int four = stoi(s.substr(i + j + k));
                    if (four > 255 || four != 0 && s[i + j + k] == '0' || four == 0 && n - i - j - k > 1) continue;
                    res.push_back(to_string(one) + "." + to_string(two) + "." + to_string(three) + "." + to_string(four));
                }
            }
        }
        return res;
    }
};