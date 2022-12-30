#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        const int MOD = 1e9 + 7;
        int n = (int) binary.size();
        int f0 = 0, f1 = 0;
        bool flag = false;
        for (int i = n - 1; ~i; i--) {
            if (binary[i] == '0') {
                f0 = (f0 + f1 + 1) % MOD;
                flag = true;
            } else {
                f1 = (f0 + f1 + 1) % MOD;
            }
        }
        return (f1 + flag) % MOD;
    };
};