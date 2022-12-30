#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = (int) s.size();
        int res = 0;
        for (char c: s) {
            if (c == '0') res++;
        }
        int x = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') {
                if (n - i - 1 >= 31) break;
                x |= 1 << (n - i - 1);
                if (x > k) break;
                res++;
            }
        }
        return res;
    }
};