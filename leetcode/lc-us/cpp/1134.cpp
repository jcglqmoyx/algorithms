#include <bits/stdc++.h>

class Solution {
public:
    bool isArmstrong(int n) {
        int a = n, b = n;
        int digits = 0;
        int sum = 0;
        while (n) {
            digits++;
            n /= 10;
        }
        while (a) {
            int digit = a % 10;
            sum += (int) pow(digit, digits);
            a /= 10;
        }
        return b == sum;
    }
};