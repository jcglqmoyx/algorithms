#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    static constexpr int MOD = 1e9 + 7;

public:
    int numberOfArrays(string s, int k) {
        int pow[10];
        pow[0] = 1;
        for (int i = 1; i < 10; i++) pow[i] = pow[i - 1] * 10;

        int n = (int) s.size();
        int f[n + 1];
        memset(f, 0, sizeof f);
        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            int num = 0;
            for (int j = i; j && i - j <= 8; j--) {
                int d = s[j - 1] - '0';
                num = d * pow[i - j] + num;
                if (d && num && num <= k) {
                    f[i] = (f[i] + f[j - 1]) % MOD;
                }
            }
        }
        return f[n];
    }
};