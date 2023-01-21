#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        int n = (int) s.size();
        if (n < 4 || n > 12) return res;
        for (int i = 1; i < 4; i++) {
            int a = stoi(s.substr(0, i));
            if (a > 255 || a != 0 && s[0] == '0' || a == 0 && i > 1) continue;
            for (int j = 1; j < 4; j++) {
                int b = stoi(s.substr(i, j));
                if (b > 255 || b != 0 && s[i] == '0' || b == 0 && j > 1) continue;
                for (int k = 1; k < 4; k++) {
                    if (i + j + k >= n) continue;
                    int c = stoi(s.substr(i + j, k));
                    if (c > 255 || c != 0 && s[i + j] == '0' || c == 0 && k > 1) continue;
                    int d = stoi(s.substr(i + j + k));
                    if (d > 255 || d != 0 && s[i + j + k] == '0' || d == 0 && n - i - j - k > 1) continue;
                    res.push_back(to_string(a) + "." + to_string(b) + "." + to_string(c) + "." + to_string(d));
                }
            }
        }
        return res;
    }
};