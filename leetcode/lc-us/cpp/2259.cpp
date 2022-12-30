#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = (int) number.size();
        string res;
        for (int i = 0; i < n; i++) {
            if (number[i] == digit) {
                if (i == n - 1 || number[i] < number[i + 1]) {
                    return number.substr(0, i) + number.substr(i + 1);
                } else {
                    res = number.substr(0, i) + number.substr(i + 1);
                }
            }
        }
        return res;
    }
};