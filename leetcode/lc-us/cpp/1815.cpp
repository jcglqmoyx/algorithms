#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxHappyGroups(int batchSize, vector<int> &groups) {
        k = batchSize;
        LL state = 0;
        int res = 0;
        for (int g: groups) {
            g %= k;
            if (!g) res++;
            else state += 1LL << (g * 5);
        }
        return res + dp(0, state);
    }

private:
    using LL = long long;
    unordered_map<LL, int> f;
    int k;

    int dp(int cur, LL state) {
        if (f.count(state)) return f[state];
        int res = 0;
        for (int i = 1; i < k; i++) {
            if ((state >> (i * 5)) % 32) {
                int t = dp((cur + i) % k, state - (1LL << (i * 5)));
                res = max(res, cur ? t : t + 1);
            }
        }
        f[state] = res;
        return res;
    }
};