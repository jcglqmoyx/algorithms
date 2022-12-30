#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long kSum(vector<int> &nums, int k) {
        using LL = long long;
        LL sum = 0;
        for (int &x: nums) {
            if (x > 0) {
                sum += x;
            } else {
                x = -x;
            }
        }
        sort(nums.begin(), nums.end());
        priority_queue<pair<LL, int>> heap;
        heap.push({sum, 0});
        while (--k) {
            auto[s, i] = heap.top();
            heap.pop();
            if (i < nums.size()) {
                heap.push({s - nums[i], i + 1});
                if (i) heap.push({s - nums[i] + nums[i - 1], i + 1});
            }
        }
        return heap.top().first;
    }
};