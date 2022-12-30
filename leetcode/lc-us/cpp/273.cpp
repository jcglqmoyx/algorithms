#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        if (!num) return "Zero";
        string res;
        for (int i = 1e9, j = 0; i; i /= 1000, j++) {
            if (num >= i) {
                res += get(num / i) + num1000[j] + ' ';
                num %= i;
            }
        }
        while (res.back() == ' ') res.pop_back();
        return res;
    }

private:
    string num1_20[19] = {
            "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven",
            "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
    };
    string num20_90[8] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string num1000[4] = {"Billion", "Million", "Thousand", ""};

    string get(int x) {
        string res;
        if (x >= 100) {
            res += num1_20[x / 100 - 1] + " Hundred ";
            x %= 100;
        }
        if (x >= 20) {
            res += num20_90[x / 10 - 2] + ' ';
            x %= 10;
        }
        if (x) {
            res += num1_20[x - 1] + ' ';
        }
        return res;
    }
};