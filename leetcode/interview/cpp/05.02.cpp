#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string printBin(double num) {
        double temp = 0.5;
        double map[32] = {0.0};
        string binary_num = "0.";
        for (double &i: map) {
            i = temp;
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