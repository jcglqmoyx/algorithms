#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> p;
    vector<long long> f;

    long long dp(int state) {
        if (f[state] != -1) return f[state];
        f[state] = INT64_MAX / 10;
        int cnt = __builtin_popcount(state);
        for (int i = 0; i < 32; i++) {
            if (state >> i & 1) {
                int sub = state ^ (1 << i);
                int gain = cnt;
                int cost = (p[i] + gain - 1) / gain;
                f[state] = min(f[state], dp(sub) + cost);
            }
        }
        return f[state];
    }

public:
    long long minimumTime(vector<int> &power) {
        int n = (int) power.size();
        p = move(power);
        f.resize(1 << n, -1);
        f[0] = 0;
        return dp((1 << n) - 1);
    }
};