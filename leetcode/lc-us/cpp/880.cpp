#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    using LL = long long;

    string decodeAtIndex(string s, int k) {
        LL len = 0;
        for (char c: s) {
            if (isdigit(c)) len *= c - '0';
            else len++;
        }
        for (int i = (int) s.size() - 1; ~i; i--) {
            k = (int) (k % len);
            if (k == 0 && isalpha(s[i])) {
                string t;
                t.push_back(s[i]);
                return t;
            }
            if (isdigit(s[i])) len /= s[i] - '0';
            else len--;
        }
        return "";
    }
};