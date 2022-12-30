#include <bits/stdc++.h>

using namespace std;

class Solution {
    int n, m;

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
        n = (int) str1.size(), m = (int) str2.size();
        if (n > m) {
            return gcdOfStrings(str2, str1);
        }
        for (int len = n; len >= 1; len--) {
            string divisor = str1.substr(0, len);
            if (n % len || m % len) {
                continue;
            }
            if (is_common_divisor(str1, divisor) && is_common_divisor(str2, divisor)) {
                return divisor;
            }
        }
        return "";
    }
};