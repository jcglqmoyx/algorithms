#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0;
        int r = 0;
        for (char c: s) {
            if (c == 'R') {
                r++;
            } else {
                r--;
            }
            if (r == 0) {
                res++;
            }
        }
        return res;
    }
};