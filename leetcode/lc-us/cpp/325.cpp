#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArrayLen(vector<int> &nums, int k) {
        unordered_map<long long, int> map;
        int n = (int) nums.size(), res = 0;
        if (nums[0] == k) res = 1;
        map[nums[0]] = 0;
        for (int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
            if (map.find(nums[i]) == map.end()) map[nums[i]] = i;
            if (nums[i] == k) res = max(res, i + 1);
            else if (map.find((long long) nums[i] - k) != map.end()) res = max(res, i - map[(long long) nums[i] - k]);
        }
        return res;
    }
};