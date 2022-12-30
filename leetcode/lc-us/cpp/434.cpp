#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        int i = 0;
        while (i < s.length()) {
            if (s[i] != ' ') {
                count++;
                while (i < s.length() && s[i] != ' ') {
                    i++;
                }
            } else {
                i++;
            }
        }
        return count;
    }
};