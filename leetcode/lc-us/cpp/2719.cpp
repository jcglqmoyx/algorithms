#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int get(string &s, int min_sum, int max_sum) {
    int n = (int) s.size();
    int f[n][min(n * 9, max_sum) + 1];
    memset(f, -1, sizeof f);
    function<int(int, int, bool)> dp = [&](int u, int sum, bool is_limited) -> int {
        if (sum > max_sum) return 0;
        if (u == n) return sum >= min_sum;
        if (!is_limited && f[u][sum] != -1) return f[u][sum];
        int res = 0, up = is_limited ? s[u] - '0' : 9;
        for (int i = 0; i <= up; i++) {
            res = (res + dp(u + 1, sum + i, is_limited && i == up)) % MOD;
        }
        if (!is_limited) f[u][sum] = res;
        return res;
    };
    return dp(0, 0, true);
}

class Solution {
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        int res = get(num2, min_sum, max_sum) - get(num1, min_sum, max_sum) + MOD;
        int sum = 0;
        for (char c: num1) sum += c - '0';
        res += sum >= min_sum && sum <= max_sum;
        return res % MOD;
    }
};