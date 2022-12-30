#include <bits/stdc++.h>

using namespace std;

class Solution {
    unordered_map<long, long> dp;

    long long f(long long n) {
        if (dp.count(n)) return dp[n];
        if (n == 1) return 0;
        if (n & 1) {
            dp[n] = min(f(n - 1), f(n + 1)) + 1;
            return dp[n];
        } else {
            dp[n] = f(n / 2) + 1;
            return dp[n];
        }
    }

public:
    int integerReplacement(int n) {
        return (int) f((long long) n);
    }
};