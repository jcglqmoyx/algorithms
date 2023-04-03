#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumTime(vector<int> &hens, vector<int> &grains) {
        int n = (int) hens.size(), m = (int) grains.size();
        sort(hens.begin(), hens.end()), sort(grains.begin(), grains.end());
        auto check = [&](int mid) {
            int j = 0;
            for (int i = 0; i < n; i++) {
                int l = 0, r = 0;
                while (j < m) {
                    if (hens[i] > grains[j]) l = max(l, hens[i] - grains[j]);
                    else r = max(r, grains[j] - hens[i]);
                    if (min(l * 2 + r, r * 2 + l) <= mid) j++;
                    else break;
                }
            }
            return j == m;
        };
        int l = 0, r = 1.5e9;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};