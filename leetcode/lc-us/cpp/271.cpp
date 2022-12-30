#include <bits/stdc++.h>

using namespace std;

class Codec {
    int hex2int(string &hex) {
        int num = 0;
        int base = 1;
        for (int i = (int) hex.length() - 1; i >= 0; i--) {
            if (isdigit(hex[i])) {
                num += (hex[i] - '0') * base;
            } else {
                num += (hex[i] - 'A' + 10) * base;
            }
            base *= 16;
        }
        return num;
    }

    string int2hex(int num) {
        string hex;
        if (num == 0) return "0";
        string digits = "0123456789ABCDEF";
        while (num) {
            hex.push_back(digits[num % 16]);
            num >>= 4;
        }
        reverse(hex.begin(), hex.end());
        if (hex.size() < 2) hex = "0" + hex;
        return hex;
    }

public:
    string encode(vector<string> &strs) {
        if (strs.empty()) return "";
        string res;
        for (const string &str: strs) {
            if (str.empty()) {
                res += "00";
                continue;
            }
            string len = int2hex((int) str.size());
            res += len + str;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        if (s.empty()) return res;
        for (int i = 0; i < s.length();) {
            string hex = s.substr(i, 2);
            int len = hex2int(hex);
            res.push_back(s.substr(i + 2, len));
            i += 2 + len;
        }
        return res;
    }
};