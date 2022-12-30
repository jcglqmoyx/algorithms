#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2) {
        vector<vector<int>> res;
        unordered_set<int> S1, S2;
        for (int x: nums1) S1.insert(x);
        for (int x: nums2) S2.insert(x);
        vector<int> v1, v2;
        for (int x: S1) {
            if (!S2.count(x)) v1.push_back(x);
        }
        for (int x: S2) {
            if (!S1.count(x)) v2.push_back(x);
        }
        res.push_back(v1), res.push_back(v2);
        return res;
    }
};