#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        int n = (int) nums.size();
        vector<int> res;
        res.reserve(n - k + 1);
        deque<int> dq;
        for (int i = 0; i < n; i++) {
            if (!dq.empty() && i - k + 1 > dq.front()) dq.pop_front();
            while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};