#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        const int MOD = 1e9 + 7, n = (int) s.size();
        vector<long long> f(n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 26; j++) {
                char a = s[i - 1];
                if (j <= 9) {
                    if (a == j + '0' || a == '*') f[i] += f[i - 1];
                } else if (i >= 2) {
                    char b = s[i - 2];
                    int y = j / 10, x = j % 10;
                    if ((a == '*' && x || a == x + '0') && (b == '*' || b == y + '0')) f[i] += f[i - 2];
                }
                f[i] %= MOD;
            }
        }
        return (int) f[n];
    }
};