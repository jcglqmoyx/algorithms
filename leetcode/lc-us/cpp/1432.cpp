#include <bits/stdc++.h>

using namespace std;

class Solution {
    static void change(string &s, char old_char, char new_char) {
        for (char &c: s) if (c == old_char) c = new_char;
    }

public:
    int maxDiff(int num) {
        string s = to_string(num), t = s;
        int n = (int) s.size(), i = 0;
        while (i < n && s[i] == '1') i++;
        if (i == n) {
            int diff = 0;
            for (int j = 0; j < n; j++) {
                diff = diff * 10 + 8;
            }
            return diff;
        }
        while (i < n && (s[i] == '0' || i && s[i] == s[0])) i++;
        char digit;
        if (i < n) digit = s[i];
        else digit = s[0];
        if (s[0] == digit) change(s, digit, '1');
        else change(s, digit, '0');
        i = 0;
        while (i < n && t[i] == '9') i++;
        if (i == n) {
            int diff = 0;
            for (int j = 0; j < n; j++) {
                diff = diff * 10 + 8;
            }
            return diff;
        }
        digit = t[i];
        change(t, digit, '9');
        return stoi(t) - stoi(s);
    }
};