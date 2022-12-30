#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int smallestFactorization(int num) {
        if (num <= 9) return num;
        long long res = 0, base = 1;
        for (int i = 9; i >= 2; i--) {
            while (num % i == 0) {
                res = res + base * i;
                num /= i;
                base *= 10;
                if (res > INT32_MAX) return 0;
            }
        }
        return num == 1 ? (int) res : 0;
    }
};