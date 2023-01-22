#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2) {
        int n = (int) nums1.size(), i = 0, j = 0;
        while (i < n) {
            while (i < n && nums1[i] < nums2[j]) i++;
            if (i < n && nums1[i] == nums2[j]) return nums1[i];
            while (j < n && nums2[j] < nums1[i]) j++;
        }
        return -1;
    }
};