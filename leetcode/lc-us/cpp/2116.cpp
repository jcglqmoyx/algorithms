#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = (int) s.size();
        if (n & 1) return false;
        for (int i = 0, r = 0; i < n; i++) {
            if (s[i] == ')' && locked[i] == '1') {
                r++;
                if (i + 1 - r < r) {
                    return false;
                }
            }
        }
        for (int i = n - 1, l = 0; ~i; i--) {
            if (s[i] == '(' && locked[i] == '1') {
                l++;
                if (n - i - l < l) {
                    return false;
                }
            }
        }
        return true;
    }
};