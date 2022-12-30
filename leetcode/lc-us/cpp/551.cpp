#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int absent = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'A') {
                if (absent) {
                    return false;
                }
                absent++;
            } else if (s[i] == 'L') {
                if (i < s.length() - 2 && s[i + 1] == 'L' && s[i + 2] == 'L') {
                    return false;
                }
            }
        }
        return true;
    }
};