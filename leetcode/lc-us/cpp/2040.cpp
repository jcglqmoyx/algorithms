#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long kthSmallestProduct(vector<int> &nums1, vector<int> &nums2, long long k) {
        using LL = long long;
        int n = (int) nums2.size();
        auto check = [&](LL limit) {
            LL cnt = 0;
            for (LL x: nums1) {
                int l = 0, r = n - 1;
                if (x < 0) {
                    while (l < r) {
                        int mi = (l + r) >> 1;
                        if (nums2[mi] * x <= limit) r = mi;
                        else l = mi + 1;
                    }
                    if (l == n - 1 && nums2[l] * x > limit) l++;
                    cnt += n - l;
                } else if (x > 0) {
                    while (l < r) {
                        int mi = (l + r + 1) >> 1;
                        if (nums2[mi] * x <= limit) l = mi;
                        else r = mi - 1;
                    }
                    if (l == 0 && nums2[l] * x > limit) l--;
                    cnt += l + 1;
                } else if (limit >= 0) cnt += n;
            }
            return cnt;
        };
        LL l = -1e10, r = 1e10;
        while (l < r) {
            LL mid = l + (r - l) / 2;
            LL cnt = check(mid);
            if (cnt < k) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};