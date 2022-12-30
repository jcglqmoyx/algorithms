#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int beautifulPartitions(string s, int k, int minLength) {
        int n = (int) s.size(), MOD = 1e9 + 7;
        function<bool(char)> is_prime = [&](char c) {
            return c == '2' || c == '3' || c == '5' || c == '7';
        };
        function<bool(int)> check = [&](int p) -> bool {
            return p == 0 || p == n || is_prime(s[p]) && !is_prime(s[p - 1]);
        };
        if (k * minLength > n || !is_prime(s[0]) || is_prime(s.back())) return 0;
        int f[k + 1][n + 1];
        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for (int i = 1; i <= k; i++) {
            int sum = 0;
            for (int j = i * minLength; j + (k - i) * minLength <= n; j++) {
                if (check(j - minLength)) sum = (sum + f[i - 1][j - minLength]) % MOD;
                if (check(j)) f[i][j] = sum;
            }
        }
        return f[k][n];
    }
};