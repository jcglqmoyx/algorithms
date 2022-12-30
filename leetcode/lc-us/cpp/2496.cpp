#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumValue(vector<string> &strs) {
        int mx = 0;
        for (auto &s: strs) {
            int x = 0;
            for (char c: s) {
                if (!isdigit(c)) {
                    x = (int) s.size();
                    break;
                }
                x = x * 10 + c - '0';
            }
            mx = max(mx, x);
        }
        return mx;
    }
};