#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        int f[26] = {};
        for (char c: s) {
            int i = c - 'a', sum = 1;
            for (int j: f) {
                sum = (sum + j) % MOD;
            }
            f[i] = sum;
        }
        int res = 0;
        for (int x: f) {
            res = (res + x) % MOD;
        }
        return res;
    }
};