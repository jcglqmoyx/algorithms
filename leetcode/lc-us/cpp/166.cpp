#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string fraction;
        if (numerator < 0 ^ denominator < 0) {
            fraction.push_back('-');
        }
        long dividend = abs(numerator), divisor = abs(denominator);
        fraction += to_string(dividend / divisor);
        if (dividend % divisor == 0) return fraction;
        fraction.push_back('.');
        unordered_map<long, int> remainders;
        long remainder = dividend % divisor;
        while (remainder) {
            if (remainders.count(remainder)) {
                fraction.insert(fraction.begin() + remainders[remainder], '(');
                fraction.push_back(')');
                break;
            }
            remainders[remainder] = (int) fraction.size();
            remainder *= 10;
            fraction += to_string(remainder / divisor);
            remainder %= divisor;
        }
        return fraction;
    }
};