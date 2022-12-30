#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int> &nums1, vector<int> &nums2) {
        int res = 0;
        for (int j = (int) nums2.size() - 1, i = (int) nums1.size() - 1; ~j; j--) {
            while (i && nums1[i - 1] <= nums2[j]) i--;
            if (nums1[i] <= nums2[j]) res = max(res, j - i);
        }
        return res;
    }
};