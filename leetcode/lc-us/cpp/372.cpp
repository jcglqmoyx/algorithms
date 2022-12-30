#include <bits/stdc++.h>

using namespace std;

class Solution {
    const int MOD = 1337;

    int pow(long a, long b) {
        long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return (int) res;
    }

public:
    int superPow(int a, vector<int> &b) {
        if (b.empty()) return 1;
        int last_digit = b.back();
        b.pop_back();
        return pow(superPow(a, b), 10) * pow(a, last_digit) % MOD;
    }
};