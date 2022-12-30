#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long singleDivisorTriplet(vector<int> &nums) {
        using ll = long long;
        int mx = 0;
        for (int x: nums) mx = max(mx, x);

        int cnt[mx + 1];
        memset(cnt, 0, sizeof cnt);
        for (int x: nums) cnt[x]++;

        ll res = 0;
        for (int num = 1; num <= mx; num++) {
            if (!cnt[num]) continue;
            for (int i = 1; i <= mx; i++) {
                if (i == num) continue;
                for (int j = i; j <= mx; j++) {
                    if (j == num) continue;
                    int sum = num + i + j;
                    if (sum % i == 0 || sum % j == 0) continue;
                    if (cnt[i] && cnt[j] && (i + j) % num == 0) {
                        if (i != j) res += 6ll * cnt[num] * cnt[i] * cnt[j];
                        else res += 6ll * cnt[num] * cnt[i] * (cnt[i] - 1) / 2;
                    }
                }
            }
        }
        return res;
    }
};