#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long res = 0;
        while (x != 0) {
            int digit = x % 10;
            res = res * 10 + digit;
            if (res > INT32_MAX || res < INT32_MIN) {
                return 0;
            }
            x /= 10;
        }
        return (int) res;
    }
};