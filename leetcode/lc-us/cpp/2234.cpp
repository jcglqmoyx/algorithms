#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumBeauty(vector<int> &flowers, long long newFlowers, int target, int full, int partial) {
        using LL = long long;

        int n = (int) flowers.size();
        sort(flowers.begin(), flowers.end(), greater<>());
        for (int &x: flowers) x = min(x, target);
        LL res = 0;
        LL sum = accumulate(flowers.begin(), flowers.end(), 0LL);
        if (sum + newFlowers >= (LL) n * target) res = (LL) full * n;
        LL pre = 0;
        for (int i = 0, j = 0; i < n; i++) {
            if (i) pre += flowers[i - 1];
            if (flowers[i] == target) continue;
            LL rest = newFlowers - (i * 1LL * target - pre);
            if (rest < 0) break;
            while (j < i || (n - j) * 1LL * flowers[j] - sum > rest) {
                sum -= flowers[j];
                j++;
            }
            rest -= (n - j) * 1LL * flowers[j] - sum;
            res = max(res, i * 1LL * full + min(target - 1LL, flowers[j] + rest / (n - j)) * 1LL * partial);
        }
        return res;
    }
};