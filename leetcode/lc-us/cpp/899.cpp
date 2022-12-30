#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1) {
            int n = (int) s.size();
            string res = s;
            for (int i = 1; i < n; i++) {
                string t = s.substr(i) + s.substr(0, i);
                res = min(res, t);
            }
            return res;
        } else {
            sort(s.begin(), s.end());
            return s;
        }
    }
};