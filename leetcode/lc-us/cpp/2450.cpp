#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countDistinctStrings(string s, int k) {
        int n = (int) s.size(), MOD = 1e9 + 7;
        int res = 1;
        for (int i = 0; i < n - k + 1; i++) {
            res = res * 2 % MOD;
        }
        return res;
    }
};