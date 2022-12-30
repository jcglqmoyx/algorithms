#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumSum(int num) {
        vector<int> digits;
        while (num) {
            digits.push_back(num % 10);
            num /= 10;
        }
        while (digits.size() < 4) {
            digits.push_back(0);
        }
        sort(digits.begin(), digits.end());
        return digits[0] * 10 + digits[2] + digits[1] * 10 + digits[3];
    }
};