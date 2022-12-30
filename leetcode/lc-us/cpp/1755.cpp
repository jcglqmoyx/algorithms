#include <bits/stdc++.h>

using namespace std;

class Solution {
    void dfs(vector<int> &res, vector<int> &nums, int len, int index, int s) {
        if (index == len) {
            res.push_back(s);
            return;
        }
        dfs(res, nums, len, index + 1, s + nums[index]);
        dfs(res, nums, len, index + 1, s);
    }

public:
    int minAbsDifference(vector<int> &nums, int goal) {
        int n = nums.size();
        vector<int> left, right;
        left.reserve(1 << ((n + 1) / 2));
        right.reserve(1 << (n / 2));
        dfs(left, nums, (n + 1) / 2, 0, 0);
        dfs(right, nums, n, (n + 1) / 2, 0);
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        int res = INT32_MAX;
        int i = 0, j = (int) right.size() - 1;
        for (int sum: left) res = min(res, abs(sum - goal));
        for (int sum: right) res = min(res, abs(sum - goal));
        while (i < left.size() && j >= 0) {
            int sum = left[i] + right[j];
            res = min(res, abs(sum - goal));
            if (sum > goal) j--;
            else i++;
        }
        return res;
    }
};