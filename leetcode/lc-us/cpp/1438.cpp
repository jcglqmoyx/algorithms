#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int> &nums, int limit) {
        int n = (int) nums.size(), res = 1;
        deque<int> min_q, max_q;
        for (int i = 0, j = 0; j < n; j++) {
            while (!min_q.empty() && min_q.back() > nums[j]) min_q.pop_back();
            while (!max_q.empty() && max_q.back() < nums[j]) max_q.pop_back();
            min_q.push_back(nums[j]), max_q.push_back(nums[j]);
            while (max_q.front() - min_q.front() > limit) {
                if (max_q.front() == nums[i]) max_q.pop_front();
                if (min_q.front() == nums[i]) min_q.pop_front();
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};