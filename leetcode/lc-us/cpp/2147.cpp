#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfWays(string s) {
        const int MOD = 1e9 + 7;
        using LL = long long;

        int seat = 0;
        for (char c: s) if (c == 'S') seat++;
        if (seat <= 1) return 0;
        if (seat & 1) return 0;
        if (seat == 2) return 1;
        int n = (int) s.size();
        int right_most = n - 1;
        for (int i = n - 1, cnt = 0; i >= 0; i--) {
            if (s[i] == 'S') cnt++;
            if (cnt == 2) {
                right_most = i;
                break;
            }
        }

        n = right_most;
        LL res = 1;
        for (int i = 0, cnt = 0; i < n; i++) {
            if (s[i] == 'S') cnt++;
            if (cnt == 2) {
                int j = i + 1;
                while (j < n && s[j] == 'P') j++;
                res = (res * (j - i)) % MOD;
                i = j - 1;
                cnt = 0;
            }
        }
        return (int) res;
    }
};