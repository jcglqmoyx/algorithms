#include <bits/stdc++.h>

using namespace std;

class Solution {
    string num1_19[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
                          "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
                          "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string num20_90[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty",
                           "Seventy", "Eighty", "Ninety"};
    string num_1000[4] = {"Billion", "Million", "Thousand", ""};

    string get(int x) {
        string res;
        if (x >= 100) {
            res += num1_19[x / 100] + ' ' + "Hundred ";
            x %= 100;
        }
        if (x >= 20) {
            res += num20_90[x / 10] + ' ';
            x %= 10;
        }
        if (x) {
            res += num1_19[x] + ' ';
        }
        return res;
    }

public:
    string numberToWords(int num) {
        if (!num) {
            return "Zero";
        }
        string res;
        if (num < 0) {
            num = -num;
            res += "Negative ";
        }
        for (int base = 1e9, i = 0; base; base /= 1000, i++) {
            if (num >= base) {
                res += get(num / base) + num_1000[i] + ' ';
                num %= base;
            }
        }
        while (res.back() == ' ') res.pop_back();
        return res;
    }
};