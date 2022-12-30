#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimumTotalCost(vector<int> &nums1, vector<int> &nums2) {
        using LL = long long;
        int n = (int) nums1.size();
        int mode = 0, mode_cnt = 0, swap_cnt = 0;
        vector<int> cnt(100001);
        LL res = 0;
        for (int i = 0; i < n; i++) {
            int x = nums1[i];
            if (x == nums2[i]) {
                swap_cnt++;
                res += i;
                cnt[x]++;
                if (cnt[x] > mode_cnt) {
                    mode = x;
                    mode_cnt = cnt[x];
                }
            }
        }

        for (int i = 0; i < n && mode_cnt * 2 > swap_cnt; i++) {
            int x = nums1[i], y = nums2[i];
            if (x != y && x != mode && y != mode) {
                res += i;
                swap_cnt++;
            }
        }
        return mode_cnt * 2 > swap_cnt ? -1 : res;
    }
};