#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        if (s.size() == 1) return 1;
        int first = 1, second = 1, cur = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == '0') {
                if (s[i - 1] > '2' || s[i - 1] == '0') {
                    return 0;
                }
                cur = first;
            } else if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') {
                cur = first + second;
            }
            first = second;
            second = cur;
        }
        return cur;
    }
};