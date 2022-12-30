#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        vector<int> res;
        unordered_set<int> set1, set2;
        for (int num: nums1) {
            set1.insert(num);
        }
        for (int num: nums2) {
            set2.insert(num);
        }
        for (int num: set1) {
            if (set2.count(num)) {
                res.push_back(num);
            }
        }
        return res;
    }
};