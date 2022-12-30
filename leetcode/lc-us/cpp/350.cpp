#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        vector<int> res;
        if (nums1.empty() || nums2.empty()) {
            return res;
        }
        unordered_map<int, int> count1, count2;
        for (int num: nums1) {
            count1[num]++;
        }
        for (int num: nums2) {
            count2[num]++;
        }
        for (auto e: count1) {
            int intersection = min(e.second, count2[e.first]);
            if (intersection) {
                for (int i = 0; i < intersection; i++) {
                    res.push_back(e.first);
                }
            }
        }
        return res;
    }
};