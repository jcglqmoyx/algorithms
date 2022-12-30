#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> fraction(vector<int> &cont) {
        int n = (int) cont.size();
        if (n == 1) return {cont[0], 1};
        int numerator = cont.back(), denominator = 1;
        for (int i = n - 1; i > 0; i--) {
            swap(numerator, denominator);
            numerator = numerator + cont[i - 1] * denominator;
        }
        return {numerator, denominator};
    }
};