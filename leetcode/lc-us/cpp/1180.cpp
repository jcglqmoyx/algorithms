#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countLetters(string s) {
        int len = 1;
        int res = 0;
        int n = s.length();
        s.push_back('A');
        for (int i = 0; i < n; i++) {
            if (s[i] == s[i + 1]) {
                len++;
            } else {
                res += len * (len + 1) / 2;
                len = 1;
            }
        }
        return res;
    }
};