#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxPower(vector<int> &stations, int r, int k) {
        using LL = long long;

        int n = (int) stations.size();

        LL v[n], diff[n];
        memset(diff, 0, sizeof diff);
        for (int i = 0; i < n; i++) {
            int left = max(0, i - r), right = min(i + r, n - 1);
            diff[left] += stations[i];
            if (right + 1 < n) diff[right + 1] -= stations[i];
        }
        for (int i = 0; i < n; i++) {
            if (i) diff[i] += diff[i - 1];
            v[i] = diff[i];
        }

        auto check = [&](LL limit) {
            LL left = k;
            LL t[n];
            memset(diff, 0, sizeof diff);
            memcpy(t, v, sizeof t);
            for (int i = 0; i < n; i++) {
                if (i) diff[i] += diff[i - 1];
                t[i] += diff[i];

                if (t[i] < limit) {
                    LL need = limit - t[i];
                    if (need > left) return false;
                    diff[i] += need;
                    if (i + r * 2 + 1 < n) diff[i + r * 2 + 1] -= need;
                    left -= need;
                }
            }
            return true;
        };

        LL lo = 0, hi = 1e10 + 1e9;
        while (lo < hi) {
            LL mid = (lo + hi + 1) >> 1;
            if (check(mid)) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
};