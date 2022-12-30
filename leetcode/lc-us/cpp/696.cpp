#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0;
        int count = 1;
        int prev = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                count++;
                if (i == (int) s.length() - 1) {
                    res += min(count, prev);
                }
            } else {
                res += min(count, prev);
                prev = count;
                count = 1;
                if (i == (int) s.length() - 1) {
                    res++;
                }
            }
        }
        return res;
    }
};