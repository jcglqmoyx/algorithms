#include <bits/stdc++.h>

using namespace std;

class Solution {
    static bool contains_zero(int num) {
        while (num) {
            int digit = num % 10;
            if (digit == 0) {
                return true;
            }
            num /= 10;
        }
        return false;
    }

public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i <= n / 2; i++) {
            int x = i, y = n - i;
            if (!contains_zero(x) && !contains_zero(y)) {
                return {x, y};
            }
        }
        return {};
    }
};