#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reformatNumber(string number) {
        string digits;
        for (char c: number) {
            if (isdigit(c)) digits.push_back(c);
        }
        string res;
        if (digits.length() == 2) return digits;
        else if (digits.length() % 3 == 0) {
            for (int i = 0; i < digits.length() - 3; i += 3)
                res += digits.substr(i, 3) + '-';
            res += digits.substr(digits.length() - 3);
        } else if ((digits.length() - 2) % 3 == 0) {
            for (int i = 0; i < digits.length() - 2; i += 3)
                res += digits.substr(i, 3) + '-';
            res += digits.substr(digits.length() - 2, 2);
            return res;
        } else {
            for (int i = 0; i < digits.length() - 4; i += 3)
                res += digits.substr(i, 3) + '-';
            res += digits.substr(digits.length() - 4, 2) + '-';
            res += digits.substr(digits.length() - 2, 2);
        }
        return res;
    }
};