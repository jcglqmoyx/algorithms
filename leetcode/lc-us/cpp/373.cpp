#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        using VVI = vector<vector<int>>;
        using VI = vector<int>;
        priority_queue<VI, VVI, greater<>> heap;
        for (int i = 0; i < nums2.size(); i++) {
            heap.push({nums1[0] + nums2[i], 0, i});
        }
        VVI res;
        while (k-- && !heap.empty()) {
            auto t = heap.top();
            heap.pop();
            res.push_back({nums1[t[1]], nums2[t[2]]});
            if (t[1] < nums1.size() - 1) {
                heap.push({nums1[t[1] + 1] + nums2[t[2]], t[1] + 1, t[2]});
            }
        }
        return res;
    }
};