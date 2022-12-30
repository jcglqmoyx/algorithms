#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string toHex(int num) {
        string digits = "0123456789abcdef";
        string hex;
        for (int i = 0; i < 32; i += 4) {
            hex += digits[num & 0Xf];
            num >>= 4;
            if (num == 0) {
                break;
            }
        }
        reverse(hex.begin(), hex.end());
        return hex;
    }
};