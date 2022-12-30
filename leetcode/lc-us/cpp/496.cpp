#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        vector<int> res(nums1.size());
        unordered_map<int, int> map;
        for (int i = 0; i < nums2.size(); i++) {
            map[nums2[i]] = i;
        }
        for (int i = 0; i < nums1.size(); i++) {
            int index = map[nums1[i]];
            bool found = false;
            for (int j = index + 1; j < nums2.size(); j++) {
                if (nums2[j] > nums1[i]) {
                    found = true;
                    res[i] = nums2[j];
                    break;
                }
            }
            if (!found) {
                res[i] = -1;
            }
        }
        return res;
    }
};