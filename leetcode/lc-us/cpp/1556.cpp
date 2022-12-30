#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string thousandSeparator(int n) {
        if (n == 0) {
            return "0";
        }
        string res;
        int count = 0;
        while (n) {
            int digit = n % 10;
            res += to_string(digit);
            count++;
            if (n > 9 && count == 3) {
                res += '.';
                count = 0;
            }
            n /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};