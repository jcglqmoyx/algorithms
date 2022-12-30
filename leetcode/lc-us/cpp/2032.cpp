#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3) {
        unordered_set<int> s1, s2, s3;
        for (int x: nums1) s1.insert(x);
        for (int x: nums2) s2.insert(x);
        for (int x: nums3) s3.insert(x);
        unordered_map<int, int> hash;
        for (int x: s1) hash[x]++;
        for (int x: s2) hash[x]++;
        for (int x: s3) hash[x]++;
        vector<int> res;
        for (auto[x, y]: hash) if (y >= 2) res.push_back(x);
        return res;
    }
};