#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countPairs(vector<int> &nums1, vector<int> &nums2) {
        using LL = long long;
        int n = (int) nums1.size();
        for (int i = 0; i < n; i++) {
            nums1[i] -= nums2[i];
        }
        sort(nums1.begin(), nums1.end());
        LL res = 0;
        for (int i = 0; i < n - 1; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (nums1[i] + nums1[mid] > 0) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (nums1[i] + nums1[l] > 0) res += n - l;
            else res += n - l - 1;
        }
        return res;
    }
};