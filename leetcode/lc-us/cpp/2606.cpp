#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int> &vals) {
        int val[128]{};
        for (char c = 'a'; c <= 'z'; c++) {
            auto idx = chars.find(c);
            if (idx == string::npos) val[c] = c - 'a' + 1;
            else val[c] = vals[idx];
        }
        int res = 0, sum = 0;
        for (char c: s) {
            if (sum < 0) sum = val[c];
            else sum = sum + val[c];
            res = max(res, sum);
        }
        return res;
    }
};