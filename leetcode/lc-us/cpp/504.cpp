#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) {
            return "0";
        }
        bool negative = false;
        if (num < 0) {
            negative = true;
            num = -num;
        }
        string base7;
        while (num != 0) {
            base7 += to_string(num % 7);
            num /= 7;
        }
        reverse(base7.begin(), base7.end());
        return negative ? '-' + base7 : base7;
    }
};