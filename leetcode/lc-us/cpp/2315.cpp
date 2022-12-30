#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countAsterisks(string s) {
        int res = 0, cnt_bar = 0;
        for (char c: s) {
            if (c == '|') cnt_bar++;
            else if (c == '*') {
                if (!(cnt_bar & 1)) {
                    res++;
                }
            }
        }
        return res;
    }
};