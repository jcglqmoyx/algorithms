#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int n = (int) s.length();
        int l = 0, r = n - 1;
        for (; l < r;) {
            char c = s[l];
            if (s[r] == c) {
                while (l < r && s[l] == c) l++;
                while (r >= l && s[r] == c) r--;
            } else {
                break;
            }
        }
        return r - l + 1;
    }
};