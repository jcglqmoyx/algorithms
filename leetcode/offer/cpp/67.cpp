#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strToInt(string str) {
        while (str[0] == ' ') {
            str.erase(str.begin());
        }
        long num = 0;
        bool negative = false;
        int index = 0;
        if (str[index] == '-') {
            negative = true;
            index++;
        } else if (str[index] == '+') {
            index++;
        }
        while (index < str.length()) {
            if (isdigit(str[index])) {
                num = num * 10 + str[index] - '0';
                if (num > INT32_MAX) {
                    if (!negative) {
                        return INT32_MAX;
                    } else {
                        return INT32_MIN;
                    }
                }
            } else {
                break;
            }
            index++;
        }
        if (negative) {
            return max((int) -num, INT32_MIN);
        } else {
            return min((int) num, INT32_MAX);
        }
    }
};