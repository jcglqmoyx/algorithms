#include <bits/stdc++.h>

using namespace std;

class Solution {
    int get(vector<int> &nums1, vector<int> &nums2) {
        int s1 = accumulate(nums1.begin(), nums1.end(), 0);
        int s2 = accumulate(nums2.begin(), nums2.end(), 0);
        int mx = -1e9;
        int sum = 0;
        for (int i = 0; i < nums1.size(); i++) {
            int diff = nums1[i] - nums2[i];
            sum = max(sum + diff, diff);
            mx = max(mx, sum);
        }
        return max(s1 - mx, s2 + mx);
    }

public:
    int maximumsSplicedArray(vector<int> &nums1, vector<int> &nums2) {
        return max(get(nums1, nums2), get(nums2, nums1));
    }
};