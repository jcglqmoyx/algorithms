#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int twoSumLessThanK(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int low = 0, high = (int) nums.size() - 1;
        int res = -1;
        while (low < high) {
            int sum = nums[low] + nums[high];
            if (sum < k) {
                res = max(res, sum);
                low++;
            } else if (sum >= k) {
                high--;
            }
        }
        return res;
    }
};