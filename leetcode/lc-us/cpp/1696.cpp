#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxResult(vector<int> &nums, int k) {
        int ans = nums[0];
        deque<pair<int, int>> q;
        q.emplace_back(nums[0], 0);
        for (int i = 1; i < (int) nums.size(); i++) {
            while (!q.empty() && i - q.front().second > k) q.pop_front();
            ans = q.front().first + nums[i];
            while (!q.empty() && q.back().first <= ans) q.pop_back();
            q.emplace_back(ans, i);
        }
        return ans;
    }
};