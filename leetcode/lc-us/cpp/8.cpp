#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        while (!s.empty() && (s.back() == ' ' || !isdigit(s.back()))) {
            s.pop_back();
        }
        while (!s.empty() && s.front() == ' ') {
            s.erase(0, 1);
        }
        if (s.empty() || isalpha(s[0])) {
            return 0;
        }
        bool negative = false;
        if (s[0] == '-') {
            negative = true;
        }
        long num = 0;
        for (int i = negative ? 1 : 0; i < s.length(); i++) {
            if (i == 0 && s[i] == '+') {
                continue;
            }
            if (isdigit(s[i])) {
                num = num * 10 + s[i] - 48;
            }
            if (num > INT32_MAX) {
                return negative ? -INT32_MAX - 1 : INT32_MAX;
            } else if (!isdigit(s[i])) {
                return negative ? (int) -num : (int) num;
            }
        }
        return negative ? (int) -num : (int) num;
    }
};