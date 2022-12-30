#include <bits/stdc++.h>

using namespace std;

class Solution {
    int get_count(vector<int> &nums, int threshold) {
        int cnt = 0, sum = 0, n = (int) nums.size();
        for (int i = 0, j = 0; j < n; j++) {
            sum += nums[j];
            while (sum > threshold) sum -= nums[i++];
            cnt += j - i + 1;
        }
        return cnt;
    }

public:
    int kthSmallestSubarraySum(vector<int> &nums, int k) {
        int l = INT32_MAX, r = 0;
        for (int num: nums) {
            l = min(l, num);
            r += num;
        }
        while (l < r) {
            int mid = l + (r - l) / 2;
            int count = get_count(nums, mid);
            if (count < k) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};