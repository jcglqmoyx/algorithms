#include <bits/stdc++.h>

using namespace std;

class Solution {
    static bool is_common_divisor(const string &str, const string &divisor) {
        for (int i = 0; i < str.size(); i += (int) divisor.size()) {
            if (str.substr(i, divisor.size()) != divisor) {
                return false;
            }
        }
        return true;
    }

public:
    string gcdOfStrings(string str1, string str2) {
        int n = (int) str1.size(), m = (int) str2.size();
        for (int len = __gcd(n, m); len >= 1; len--) {
            string divisor = str1.substr(0, len);
            if (n % len || m % len) continue;
            if (is_common_divisor(str1, divisor) && is_common_divisor(str2, divisor)) return divisor;
        }
        return "";
    }
};