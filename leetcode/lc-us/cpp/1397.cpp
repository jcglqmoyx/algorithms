#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> fail;
    const int MOD = 1e9 + 7;

    int get(const string &s1, const string &s2, const string &e) {
        int n = (int) s1.size(), m = (int) e.size(), f[n][m][2][2];
        memset(f, -1, sizeof f);
        function<int(int, int, bool, bool)> dp = [&](int i, int pos, bool is_limited1, bool is_limited2) -> int {
            if (pos == m) return 0;
            if (i == n) return 1;
            if (f[i][pos][is_limited1][is_limited2] != -1) return f[i][pos][is_limited1][is_limited2];
            int res = 0;
            for (char c = is_limited1 ? s1[i] : 'a', up = is_limited2 ? s2[i] : 'z'; c <= up; ++c) {
                int next = pos;
                while (next != -1 && c != e[next]) next = fail[next];
                res += dp(i + 1, next + 1, is_limited1 && c == s1[i], is_limited2 && c == up);
                res %= MOD;
            }
            f[i][pos][is_limited1][is_limited2] = res;
            return res;
        };
        return dp(0, 0, true, true);
    }

public:
    int findGoodStrings(int n, string s1, string s2, string evil) {
        fail = vector<int>(evil.size() + 1, -1);
        int l = -1, r = 0;
        while (r < evil.size()) {
            while (l == -1 || evil[l] == evil[r]) fail[++r] = ++l;
            l = fail[l];
        }
        return get(s1, s2, evil);
    }
};