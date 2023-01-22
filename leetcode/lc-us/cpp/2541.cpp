#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minOperations(vector<int> &nums1, vector<int> &nums2, int k) {
        using LL = long long;
        int n = (int) nums1.size();
        if (k == 0) {
            for (int i = 0; i < n; i++) {
                if (nums1[i] != nums2[i]) {
                    return -1;
                }
            }
            return 0;
        }
        LL g = 0, l = 0, res = -1;
        for (int i = 0; i < n; i++) {
            int diff = nums1[i] - nums2[i];
            if (diff % k) return -1;
            if (nums1[i] > nums2[i]) {
                g += diff;
            } else if (nums1[i] < nums2[i]) {
                l += -diff;
            }
        }
        if (g == l) res = g / k;
        return res;
    }
};