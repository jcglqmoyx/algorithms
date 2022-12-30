#include <bits/stdc++.h>

using namespace std;

class Solution {
    long long diff(long long &a, long long &b) {
        long long d = a ^ b, r = ((d ^ b) & d) ^ d, s = 0;
        while (r) r >>= 1, s += 1;
        return d >>= s, d <<= s;
    }

public:
    long long ringGame(vector<long long> &challenge) {
        int lg = (int) challenge.size();
        long long res = 1e18;
        for (int i = 0; i < lg; i++) {
            long long value = challenge[i];
            if (value >= res) continue;
            int le = (i - 1 + lg) % lg, ri = (i + 1) % lg;
            long long x = value, y = value;
            while (le != ri) {
                long long ple = (x | y) >= challenge[le] ? (x | y | challenge[le]) : 0;
                long long pri = (x | y) >= challenge[ri] ? (x | y | challenge[ri]) : 0;
                if (ple == 0 && pri == 0) {
                    long long dle = diff(challenge[le], y);
                    long long dri = diff(challenge[ri], y);
                    if (dle < value) dle |= value;
                    if (dri < value) dri |= value;
                    x = min(dle, dri);
                    if (x >= res) break;
                    value = max(value, x);
                    continue;
                }
                if (ple > pri) y = challenge[le] | y, le = (le - 1 + lg) % lg;
                else y = challenge[ri] | y, ri = (ri + 1) % lg;
            }
            if ((x | y) < challenge[le]) x = diff(challenge[le], y);
            if (x < value) x = x | value;
            res = min(res, x);
        }
        return res;
    }
};