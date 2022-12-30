#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> res;
        if (nums.empty()) return res;
        res.reserve(nums.size() - k + 1);
        deque<int> q;
        for (int i = 0; i < k; i++) {
            while (!q.empty() && nums[i] > nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        res.push_back(nums[q.front()]);
        for (int i = k; i < nums.size(); i++) {
            while (!q.empty() && nums[i] > nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            while (!q.empty() && q.front() <= i - k) {
                q.pop_front();
            }
            res.push_back(nums[q.front()]);
        }
        return res;
    }
};