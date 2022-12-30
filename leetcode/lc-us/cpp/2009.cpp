#include <bits/stdc++.h>

using namespace std;

class Solution {
    int get(vector<int> &nums, int val) {
        int l = 0, r = (int) nums.size() - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (nums[mid] > val) r = mid - 1;
            else l = mid;
        }
        return l;
    }

public:
    int minOperations(vector<int> &nums) {
        int n = (int) nums.size();
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int res = n;
        int m = (int) nums.size();
        for (int i = 0; i < m; i++) {
            res = min(res, n - (get(nums, nums[i] + n - 1) - i + 1));
        }
        return res;
    }
};