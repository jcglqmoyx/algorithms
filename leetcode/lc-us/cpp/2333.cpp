#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minSumSquareDiff(vector<int> &nums1, vector<int> &nums2, int k1, int k2) {
        using LL = long long;
        int n = (int) nums1.size();
        vector<int> cnt(1e5 + 1);
        for (int i = 0; i < n; i++) cnt[abs(nums1[i] - nums2[i])]++;
        int k = k1 + k2;
        for (int i = 1e5; i && k; i--) {
            if (!cnt[i]) continue;
            int change = min(k, cnt[i]);
            k -= change;
            cnt[i] -= change;
            cnt[i - 1] += change;
        }
        LL res = 0;
        for (int i = 1e5; i; i--) {
            if (cnt[i]) {
                res += cnt[i] * (LL) i * i;
            }
        }
        return res;
    }
};