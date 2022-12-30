#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int n = (int) nums.size(), ans;
        int min_diff = INT32_MAX;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int low = i + 1, high = n - 1;
            while (low < high) {
                int sum = nums[i] + nums[low] + nums[high];
                if (sum == target) return target;
                int diff = abs(sum - target);
                if (diff < min_diff) {
                    ans = sum;
                    min_diff = diff;
                }
                if (sum < target) {
                    int p = low + 1;
                    while (p < high && nums[p] == nums[p - 1]) p++;
                    low = p;
                }
                if (sum > target) {
                    int q = high - 1;
                    while (low < q && nums[q] == nums[q + 1]) q--;
                    high = q;
                }
            }
        }
        return ans;
    }
};