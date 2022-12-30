#include <bits/stdc++.h>

using namespace std;

class Solution {
    unordered_map<int, int> c_plus_d;
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        for (int i: nums3) {
            for (int j: nums4) {
                int s = i + j;
                c_plus_d[s]++;
            }
        }
        int cnt = 0;
        for (int i: nums1) {
            for (int j: nums2) {
                int s = -i - j;
                cnt += c_plus_d[s];
            }
        }
        return cnt;
    }
};