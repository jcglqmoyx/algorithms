#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int total = (int) nums1.size() + (int) nums2.size();
        return total & 1 ? find(nums1, 0, nums2, 0, total / 2 + 1) :
               (find(nums1, 0, nums2, 0, total / 2) + find(nums1, 0, nums2, 0, total / 2 + 1)) / 2.0;
    }

    int find(vector<int> &nums1, int i, vector<int> &nums2, int j, int k) {
        if (nums1.size() - i > nums2.size() - j) return find(nums2, j, nums1, i, k);
        if (i == nums1.size()) return nums2[j + k - 1];
        if (k == 1) return min(nums1[i], nums2[j]);
        int si = min((int) nums1.size(), i + k / 2), sj = j + k / 2;
        if (nums1[si - 1] < nums2[sj - 1]) return find(nums1, si, nums2, j, k - (si - i));
        else return find(nums1, i, nums2, sj, k - k / 2);
    }
};