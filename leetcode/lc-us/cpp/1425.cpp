#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int constrainedSubsetSum(vector<int> &nums, int k) {
        int n = (int) nums.size();
        vector<int> f(n);
        f[0] = nums[0];
        deque<int> q;
        q.push_back(0);
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            while (!q.empty() && i - q.front() > k) q.pop_front();
            f[i] = max(nums[i], f[q.front()] + nums[i]);
            res = max(res, f[i]);
            while (!q.empty() && f[i] >= f[q.back()]) q.pop_back();
            q.push_back(i);
        }
        return res;
    }
};