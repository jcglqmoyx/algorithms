#include <bits/stdc++.h>

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) {
            return false;
        }
        int sum = 1;
        for (int d = 2; d <= (int) sqrt(num); d++) {
            if (num % d == 0) {
                int quotient = num / d;
                sum += d;
                sum += quotient == d ? 0 : quotient;
            }
        }
        return sum == num;
    }
};