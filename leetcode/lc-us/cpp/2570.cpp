#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2) {
        vector<vector<int>> res;
        int n = (int) nums1.size(), m = (int) nums2.size();
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (nums1[i][0] < nums2[j][0]) res.push_back(nums1[i]), i++;
            else if (nums1[i][0] > nums2[j][0]) res.push_back(nums2[j]), j++;
            else res.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]}), i++, j++;
        }
        while (i < n) res.push_back(nums1[i++]);
        while (j < m) res.push_back(nums2[j++]);
        return res;
    }
};