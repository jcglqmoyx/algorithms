#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSum(vector<int> &nums1, vector<int> &nums2) {
        using LL = long long;
        const int MOD = 1e9 + 7;
        int n = (int) nums1.size(), m = (int) nums2.size();
        int i = 0, j = 0;
        LL x = 0, y = 0;
        while (i < n && j < m) {
            if (nums1[i] < nums2[j]) {
                x += nums1[i++];
            } else if (nums1[i] > nums2[j]) {
                y += nums2[j++];
            } else {
                x = y = max(x, y) + nums1[i++], j++;
            }
        }
        while (i < n) x += nums1[i++];
        while (j < m) y += nums2[j++];
        return (int) (max(x, y) % MOD);
    }
};