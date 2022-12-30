#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string modifyString(string s) {
        int n = (int) s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                for (char c = 'a'; c <= 'z'; c++) {
                    if (i == 0 || i > 0 && s[i - 1] != c) {
                        if (i == n - 1 || i < n - 1 && s[i + 1] != c) {
                            s[i] = c;
                            break;
                        }
                    }
                }
            }
        }
        return s;
    }
};