#include <bits/stdc++.h>

using namespace std;

class Solution {
    using LL = long long;
    constexpr static int MOD = 1e9 + 7;

    LL res = 0;
    int forbidden = 0;
    int cnt[31] = {0};

    static LL quick_pow(LL a, int b) {
        LL ret = 1;
        while (b) {
            if (b & 1) ret = ret * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return ret;
    }

    void dfs(int u, int selected_numbers, LL t) {
        if (u == 31) {
            if (selected_numbers) res = (res + t) % MOD;
            return;
        }
        if (forbidden >> u & 1) {
            dfs(u + 1, selected_numbers, t);
            return;
        }
        if (cnt[u]) {
            bool valid = true;
            for (int i = 2; i < u; i++) {
                if (selected_numbers >> i & 1 && __gcd(u, i) > 1) {
                    valid = false;
                    break;
                }
            }
            if (valid) dfs(u + 1, selected_numbers | 1 << u, t * cnt[u] % MOD);
        }
        dfs(u + 1, selected_numbers, t);
    }

public:
    int numberOfGoodSubsets(vector<int> &nums) {
        int unwanted[] = {4, 8, 9, 12, 16, 18, 20, 24, 25, 27, 28};
        for (int x: unwanted) {
            forbidden |= 1 << x;
        }
        for (int x: nums) cnt[x]++;
        dfs(2, 0, 1);
        if (cnt[1]) {
            res = (res * quick_pow(2, cnt[1])) % MOD;
        }
        return (int) res;
    }
};