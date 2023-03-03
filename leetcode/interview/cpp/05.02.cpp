#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string printBin(double num) {
        double temp = 0.5;
        string binary_num = "0.";
        for (int i = 0; i < 6; i++) {
            if (num >= temp) {
                num -= temp;
                binary_num.push_back('1');
            } else {
                binary_num.push_back('0');
            }
            temp /= 2;
            if (num == 0.0) break;
        }
        if (num > 0) return "ERROR";
        return binary_num;
    }
};