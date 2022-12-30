#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countTexts(string s) {
        const int MOD = 1e9 + 7;
        int n = (int) s.size();
        vector<int> f(n + 1);
        f[0] = 1;
        unordered_map<int, int> M;
        for (int i = 2; i <= 9; i++) {
            if (i == 7 || i == 9) M[i] = 4;
            else M[i] = 3;
        }
        for (int i = 1; i <= n; i++) {
            int d = s[i - 1] - '0';
            for (int j = i; j >= 1 && s[j - 1] == s[i - 1]; j--) {
                if (i - j + 1 > M[d]) break;
                f[i] = (f[i] + f[j - 1]) % MOD;
            }
        }
        return f[n];
    }
};
