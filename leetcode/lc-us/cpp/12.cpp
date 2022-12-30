#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string roman_numerals[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int nums[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string roman;
        int index = 0;
        while (num && index < 13) {
            while (num >= nums[index]) {
                num -= nums[index];
                roman += roman_numerals[index];
            }
            index++;
        }
        return roman;
    }
};