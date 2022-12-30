#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        int n = (int) s.size();
        for (int i = 0; i < n; i++) {
            string w;
            int j = i;
            while (j < n) {
                w.push_back(s[j]);
                j++;
                if (j % k == 0) break;
            }
            i = j - 1;
            res.push_back(w);
        }
        auto &w = res.back();
        while (w.size() < k) {
            w.push_back(fill);
        }
        return res;
    }
};