#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int left = 0;
        for (char c: s) {
            if (c == ')') {
                left--;
            }
            if (left) {
                res += c;
            }
            if (c == '(') {
                left++;
            }
        }
        return res;
    }
};