#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int xorAllNums(vector<int> &nums1, vector<int> &nums2) {
        int n = (int) nums2.size();
        int cnt[32] = {};
        for (int x: nums2) {
            for (int i = 0; i < 32; i++) {
                if (x >> i & 1) cnt[i]++;
            }
        }
        int res = 0;
        for (int x: nums1) {
            for (int i = 0; i < 32; i++) {
                if (x >> i & 1) {
                    if (n - cnt[i] & 1) res ^= 1 << i;
                } else {
                    if (cnt[i] & 1) res ^= 1 << i;
                }
            }
        }
        return res;
    }
};